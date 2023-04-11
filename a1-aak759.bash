#!/bin/bash
#prompt user for action character input
echo "Enter one of the following actions or press [CTRL+D] to exit: "
echo "C - create a new item: "
echo "R - read an existing item: "
echo "U - update an existing item: "
echo "D - delete an existing item: "
echo "CTRL-D to exit this menu: "
#create directory if not existing
mkdir -p ./data/
#function prompts for item information
#read -p "Your question here: "
#echo "$REPLY" > somefile
create_item(){
        #prompts and variables
        read -p "Enter item number as non-negative integer: " item_number
        read -p "Enter simple name: " simple_name
        read -p "Enter item name: " item_name
        read -p "Enter current item quantity: " current_quantity
        read -p "Enter maximum_quanity: " max_quantity
        read -p "Enter item description: " description
        #add .item extension to item number
        echo $item_number > ./data/$item_number.item
        #add formatted data to data file
        #create queries.log
        #Update data/queries.log by adding the following line:
        #CREATED: date - simple_name
        #where simple_name is the itemâs short name and date is the output from the date command.
        echo -e "CREATED: $(date) - $simple_name" >> ./data/queries.log
        echo -e "simple_name $item_name\n$current_quantity $max_quantity\n$description" > ./data/$item_number.item
return 0
}
#function prompts for item number then searches data file and returns info or error msg
read_item(){
        read -p "Enter item number of product you wish to search for: " item_number
        #input = $item_number.item
        #echo $input
        #search for item by number
        #find . -type f -name "$item_number"
        #echo file data if file exists
        if [ -f  "./data/$item_number.item" ];then
                #cat plus path and added extension
                cat ./data/$item_number.item
                #echo $simple_name
                #echo $item_name
                #echo $current_quantity
                #echo $max_quantity
                #echo $description
                return 0
        else
                #if unable to read item number in file echo error message
                echo "ERROR: item not found" 
                return 1
        fi
return 0
}
update_item(){
        #prompts and variables
        read -p "Enter item number of product you wish to update: " item_number
        if [ -f "./data/$item_number.item" ]; then
                #use temp vars to hold potential updates
                read -p "Enter simple name: " simple_name_tmp
                read -p "Enter item name: " item_name_tmp
                read -p "Enter current item quantity: " current_quantity_tmp
                read -p "Enter maximum_quanity: " max_quantity_tmp
                read -p "Enter item description: " description_tmp
                count=0
                while read line; do
                        #read file
                        if [[ $count == 0 ]]; then
                              read simple_name item_name <<< $line
                        fi
                        if [[ $count == 1 ]]; then
                              read current_quantity max_quantity <<< $line
                        fi
                        if [[ $count == 2 ]]; then
                              read description  <<< $line
                        fi
                        $count += 1
                done < ./data/$item_number.item
                if [[ "$simple_name_tmp" != "" ]]; then
                        simple_name = $simple_name_tmp
                        #echo $simple_name
                fi
                if [[ "$item_name_tmp" != "" ]]; then
                        item_name = item_name_tmp
                        #echo $item_name
                fi
                if [[ "$current_quantity_tmp" != "" ]]; then
                        current_quantity = current_quantity_tmp
                        #echo $current_quantity
                fi
                if [[ "$max_quantity_tmp" != "" ]]; then
                        max_quantity = max_quantity_tmp
                        #echo $max_quantity
                fi
                if [[ "$description_tmp" != "" ]]; then
                        description = description_tmp
                fi
                echo -e "simple_name $item_name\n$current_quantity $max_quantity\n$description" > ./data/$item_number.item
                echo -e "UPDATED: $(date) - $simple_name" >> ./data/queries.log
                echo "$simple_name was successfully updated."
                return 0
        else
                echo "ERROR: item not found"
                return 1
        fi
return 0
}
delete_item(){
        read -p "Enter item number of product you wish to delete: " item_number
        if [ -f "./data/$item_number.item" ]; then
                read simple_name item_name < ./data/$item_number.item
                read current_quantity max_quantity < ./data/$item_number.item
                read description < ./data/$item_number.item
                rm ./data/$item_number.item
                echo -e "DELETED: $(date) - $simple_name" >> ./data/queries.log
                echo "$simple_name was successfully deleted."
                return 0
        else
                echo "ERROR: item not found"
                return 1
        fi
return 0 
}
#read the user character selection
read action
#cases for non case sensitive input of action character options
        case "$action" in
        c|C)
                echo -n "You entered C"
                echo 
                #call function to create file
                create_item
                ;;
        r|R)
                echo -n "You entered R"
                echo
                #call function to read file
                read_item
                ;;
        u|U)
                echo -n "You entered U"
                echo
                update_item
                ;;
        d|D)
                echo -n "You entered D"
                echo
                delete_item
                ;;
        *)
                echo -n "You did NOT enter a valid action"
                echo
                ;;
        esac
