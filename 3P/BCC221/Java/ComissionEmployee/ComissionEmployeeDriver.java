public class ComissionEmployeeDriver {
    public static void main (String args[]) {
        ComissionEmployee employee = new ComissionEmployee("Sue", "Jones", "222-222-222", 10000, 0.06);
        System.out.println(employee);

        BasePlusComissionEmployee employee2 = new BasePlusComissionEmployee(8000, "Sue", "Jones", "222-222-222", 10000, 0.06);
        System.out.println(employee);
        System.out.println("\nTotal salary: "+ employee2.earning());
    }
}
