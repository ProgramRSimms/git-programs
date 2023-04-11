public class P3Main
{
    public static void main(String[] args) throws Exception
    {

        String jdbcUrl = "jdbc:sqlite:/" + System.getProperty("user.dir") + "\\propertyDB.db";

        P3Program pgm = new P3Program(jdbcUrl, "", "");
        pgm.runProgram();
    }
}