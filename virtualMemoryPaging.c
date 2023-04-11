#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#define PAGE_SIZE_BITS 7
#define PAGE_SIZE (1 << PAGE_SIZE_BITS)
#define PAGE_TABLE_SIZE (1 << 13)
#define FRAME_TABLE_SIZE (1 << 8)

/*
With a page size of 128 bytes, we can represent the offset within a page with 7 bits (2^7 = 128). 
Therefore, the number of bits needed to represent the page number is 12 (2^12 = 4096, the virtual memory size). 
Thus, we need 12 bits to represent the page number and 7 bits to represent the offset within the page.

The page table size is the number of pages we can store in the page table, which is equal to the size of virtual 
memory divided by the page size. So in this case, the page table size is 4096 / 128 = 32.

The frame table size is the number of frames we can store in the frame table, which is equal to the size of 
physical memory divided by the frame size. So in this case, the frame table size is 1024 / 128 = 8.

*/

// Page table entry struct
typedef struct {
    int valid; // valid bit = 1 if the page is in physical memory, 0 otherwise
    int frame; // The frame number of the page in physical memory
} PT;

// Frame table entry struct
typedef struct {
    int in_use; // 1 if the frame is in use, 0 otherwise
    int page;   // The page number of the page currently in the frame
    int prev;   // The previous frame in the LRU list
    int next;   // The next frame in the LRU list
} FT;

/*********************** Main ********************************/
int main(int argc, char *argv[]){
    //printf("1st line of main function\n");//debugging
    //fflush(stdout);
    //check for valid command line args
    if (argc != 3){
        fprintf(stderr, "Usage = %s <input_file> <output_file>\n", argv[0]);
        printf("Usage = %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    //access modes: read binary mode & write binary mode
    FILE *fileIn = fopen(argv[1], "rb");
    FILE *fileOut = fopen(argv[2], "wb");
    if (fileIn == NULL){
        fprintf(stderr, "Failed to open input file %s\n", argv[1]);
        //printf("Failed to open input file %s\n", argv[1]);
        //fflush(stdout);
        exit(1);
    }
    //printf("After reading input file\n");//debugging
    if (fileOut == NULL) {
        fprintf(stderr, "Failed to open output file %s\n", argv[2]);
        //printf("Failed to open output file %s\n", argv[2]);
        //fflush(stdout);
        exit(1);
    }
    PT page_table[PAGE_TABLE_SIZE];
    FT frame_table[FRAME_TABLE_SIZE];//keep track of which frame is free/allocated

    //printf("Before initializing page table\n");//debugging
    //fflush(stdout);
    // Initialize the page table
    for (int i = 0; i < PAGE_TABLE_SIZE; i++){
        page_table[i].valid = 0;
        page_table[i].frame = -1;
    }
    //printf("Before initializing frame table\n");//debugging
    //fflush(stdout);
    // Initialize the frame table (initialized = 0, in-use = 1)
    for (int i = 1; i < FRAME_TABLE_SIZE; i++){
        frame_table[i].in_use = 0;
        frame_table[i].page = -1;
        frame_table[i].prev = -1;
        frame_table[i].next = -1;
    }

    //allocated frame 0 for OS 
    frame_table[0].in_use = 1;
    //printf("Before reading logical address\n");//debugging
    //fflush(stdout);
    // Read logical addresses, find page number, check valid bit, store frame if needed 
 
    //count page faults initialized to zero
    int page_faults = 0;

    while (!feof(fileIn)){
        unsigned int logical_address;
        unsigned long physical_address;
        // Read a logical address from input
        size_t read_elements = fread(&logical_address, sizeof(unsigned int), 1, fileIn);
        // Error checking of binary input
        // Check for end of file
        if (feof(fileIn)) {
           // printf("Error: End of file reached while reading logical addresses\n");//debugging
            break;
        }
        //printf("0x%016x\n", logical_address);
        //fprintf(fileOut,"0x%016x\n", logical_address);
        fwrite(&physical_address, sizeof(unsigned long), 1, fileOut);
        if (read_elements != 1) {
            if (feof(fileIn)) {
                // End of file reached
                break;
            } else if (ferror(fileIn)) {
                // Error occurred while reading the file
                perror("Error reading input file");
                fclose(fileIn);
                fclose(fileOut);
                exit(1);
            }
        }

        // Check if the logical address is within the valid range of addresses
        if (logical_address >= (1 << (PAGE_SIZE_BITS + 12))) {
            //printf("Error: Logical address %u is not within the valid address space\n", logical_address);
            //fflush(stdout);
            //continue processing
            continue;
        }

        // Find the page number
        int page_number = logical_address >> PAGE_SIZE_BITS;

        // Check if page number is within bounds
        if (page_number >= PAGE_TABLE_SIZE) {
            fprintf(stderr, "Error: Page number %d exceeds maximum page table size\n", page_number);
            exit(1);
        }

        // Check if the logical address is within the valid address space
        unsigned long long max_address = ((unsigned long long)1 << (sizeof(unsigned long long) * CHAR_BIT - 1)) - 1ULL;        
        if (logical_address > max_address) {
            //fprintf(stderr, "Error: Logical address %u is not within the valid address space\n", logical_address);
            exit(1);
        }

        // Check if the page is in physical memory (valid bit = 1)
        if (page_table[page_number].valid){
            // The page is in physical memory, so map the logical address to a physical address
            int frame_number = page_table[page_number].frame;
            int offset = logical_address & (PAGE_SIZE - 1);
            physical_address = (frame_number << PAGE_SIZE_BITS) | offset;

            // Check if physical address is valid
            unsigned long long max_address = ((unsigned long long)1 << ((sizeof(unsigned long long) * 8) - 1)) - 1;// maximum addressable memory cast 1 to prevent overflow
            if (physical_address > max_address) {
                fprintf(stderr, "Error: Physical address %lu exceeds maximum addressable memory\n", physical_address);
                exit(1);
            }

            // Write the output
            fwrite(&physical_address, sizeof(unsigned long long), 1, fileOut);

            // Update the LRU list
            if (frame_table[frame_number].prev != -1) {
                int prev_frame = frame_table[frame_number].prev;
                int next_frame = frame_table[frame_number].next;
                frame_table[prev_frame].next = next_frame;
            
                if (next_frame != -1) {
                    frame_table[next_frame].prev = prev_frame;
                }

            frame_table[frame_number].prev = -1;
            frame_table[frame_number].next = frame_table[0].next;
            
            if (frame_table[0].next != -1) {
                    frame_table[frame_table[0].next].prev = frame_number;
                }

                frame_table[0].next = frame_number;
            }
        }
        // Page fault (valid bit = 0)
        else{
            // The page is not in physical memory, so allocate a frame for it
            //search for an unused frame (!frame_table[i].in_use), break out of the loop if found. 
            //This ensures that a single frame is only allocated to a single page at any given time.

            int frame_number = -1;
            for (int i = 1; i < FRAME_TABLE_SIZE; i++){
                if (!frame_table[i].in_use) {
                    frame_number = i;
                    break;
                }
            }
            if (frame_number == -1) {
                // Update page fault counter
                page_faults++;

                // Find the last frame in the LRU list
                int last_frame = 0;
                while (frame_table[last_frame].next != -1) {
                    last_frame = frame_table[last_frame].next;
                }
                frame_number = last_frame;

                // Invalidate the previous page associated with the victim frame
                int victim_page_number = frame_table[frame_number].page;
                page_table[victim_page_number].valid = 0;
                page_table[victim_page_number].frame = -1;


                // Update the page table
                //printf("Updating page table...\n");//debugging
                //fflush(stdout);
                page_table[page_number].valid = 1;
                page_table[page_number].frame = frame_number;

                // Update the frame table and reverse map to point to the allocated frame
                //printf("Updating frame table...\n");//debugging
                //fflush(stdout);
                frame_table[frame_number].in_use = 1;
                frame_table[frame_number].page = page_number;

                // Map the logical address to a physical address
                int offset = logical_address & (PAGE_SIZE - 1);
                physical_address = (frame_number << PAGE_SIZE_BITS) | offset;

                // Write the output
                fwrite(&physical_address, sizeof(unsigned long), 1, fileOut);

                // Update the LRU list
                //printf("Updating LRU list..\n");//debugging
                //fflush(stdout);

                if (frame_table[frame_number].prev != -1) {
                    // The frame is already in the LRU list, so move it to the front
                    int prev_frame = frame_table[frame_number].prev;
                    int next_frame = frame_table[frame_number].next;

                    frame_table[prev_frame].next = next_frame;
                    if (next_frame != -1) {
                        frame_table[next_frame].prev = prev_frame;
                    }

                    frame_table[frame_number].prev = -1;
                    frame_table[frame_number].next = frame_table[0].next;
                    if (frame_table[0].next != -1) {
                        frame_table[frame_table[0].next].prev = frame_number;
                    }

                    frame_table[0].next = frame_number;
                } 
                else {
                    // The frame is not in the LRU list, so add it to the front
                    frame_table[frame_number].prev = -1;
                    frame_table[frame_number].next = frame_table[0].next;

                    if (frame_table[0].next != -1) {
                        frame_table[frame_table[0].next].prev = frame_number;
                    }

                    frame_table[0].next = frame_number;
                }

                // Remove the victim frame from the LRU list if necessary
                if (frame_number != -1 && frame_table[frame_number].prev != -1) {
                    int prev_frame = frame_table[frame_number].prev;
                    int next_frame = frame_table[frame_number].next;

                    frame_table[prev_frame].next = next_frame;
                    if (next_frame != -1) {
                        frame_table[next_frame].prev = prev_frame;
                    }

                    frame_table[frame_number].prev = -1;
                    frame_table[frame_number].next = -1;
                }
            }

        }
    }
    // Output # of page faults
    printf("Number of page faults: %d\n", page_faults);

    // Close files
    fclose(fileIn);
    fclose(fileOut);

    // Free dynamically allocated memory
    //free(page_table);
    //free(frame_table);

    return 0;
}