import java.sql.*;
import java.util.Date;

public class P3Program
{
    private Connection connect = null;
    private Statement statement = null;
    private PreparedStatement preparedStatement = null;
    private ResultSet resultSet = null;
    public static final int ER_DUP_ENTRY = 1062;
    public static final int ER_DUP_ENTRY_WITH_KEY_NAME = 1586;
    public static final String[] strPropertyIdM = {"MTNDDD","NYCCC","HOMEJJJ","END"};
    public P3Program(String url, String user, String password){
        try {
            connect = DriverManager.getConnection(url, user, password);
            connect.setTransactionIsolation(Connection.TRANSACTION_READ_COMMITTED);       
            }
        catch (SQLException e){
            System.out.println("Error connecting to SQLite database");
            e.printStackTrace();
        }
    }
    public void runProgram() throws Exception{

        // Code the #2 functionalities that start in page 5 of the problem statement

        // functionality 2.a
       try 
        {

            // Statement allows us to issue SQL statements to the database
            statement = connect.createStatement();
            // Get the sections and save in resultSet
            resultSet = statement
                    .executeQuery("select * from Property");
            resultSet = statement
                    .executeQuery("select * from Customer");
            resultSet = statement
                    .executeQuery("select * from Rental");
            printStudents("Beginning Property", resultSet);
            printStudents("Beginning Customer", resultSet);
            printStudents("Beginning Rental", resultSet);
        // functionality 2.b

        // functionality 2.c

        // functionality 2.d

        // functionality 2.e

        // functionality 2.f

        // functionality 2.g

        // functionality 2.h

        // functionality 2.i

        // functionality 2.j

        // functionality 2.k

        // functionality 2.l

        // functionality 2.m
//preparedStatement = connect.prepareStatement
    //("insert values "
    //+"(\"20181Sp\", ?, ?, ?, ?, ?, ?)");
// semester, courseNr, sectNr, prof, classDays, classTime, room
// Parameters start with 1

        // Remember to close the statement and connect(ion)
        statement.close();
        connect.close();
    }

    private void printCustomers(String title, ResultSet resultSet) throws SQLException
    {
        // Your output for this must match the format of my sample output exactly.
        // custNr, name, baseLoc, birthDt, gender
    //The current position in resultSet is before the first row
    System.out.printf("%s\n", title);
    System.out.printf("%-4s %-4s %-4s %-4s %-4s\n", "Customer", "name", "baseLoc", "birthDt", "gender");

    // print each tuple in the result set
    while (resultSet.next())
    {
        // It is possible to get the columns via name
        // also possible to get the columns via the column number
        // which starts at 1

        int customerNr = resultSet.getInt("customerNr");
        String name = resultSet.getString("name");
        String baseLoc = resultSet.getString("baseLoc");
        String birthDt = resultSet.getString("birthDt");
        String gender = resultSet.getString("gender");
        
        System.out.printf("%-7d %-5s \n", studentNr, name, baseLoc, birthDt, gender);
    }
    System.out.printf("\n");
    // remember to close your resultSet
    resultSet.close();
}