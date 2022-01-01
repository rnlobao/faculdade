public class BasePlusComissionEmployee extends ComissionEmployee {
    private double baseSalary;

    public BasePlusComissionEmployee(double baseSalary, String firsName, String lastName, String socialSecurityNumber, double grossSales, double comissionRate) {
        super(firsName, lastName, socialSecurityNumber, grossSales, comissionRate);
        setBaseSalary(baseSalary);
    }

    public double getBaseSalary() {
        return baseSalary;
    }

    public void setBaseSalary(double baseSalary) {
        this.baseSalary = baseSalary < 0.0 ? 0.0 : baseSalary;
    }

    public double earning() {
        return getBaseSalary() + super.earnings();
    }

    public String toString() {
        return String.format("%s \n%s\n %s: %.2f", "based-salaried", super.toString(), "base salary", getBaseSalary());
    }
}
