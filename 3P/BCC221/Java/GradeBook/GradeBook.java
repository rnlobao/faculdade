public class GradeBook {
    private String courseName;

    //Construtor
    public GradeBook(String name) {
        setCourseName(name);
    }

    //Setter
    public void setCourseName(String name) {
        this.courseName = name;
    }

    //Getter
    public String getCourseName() {
        return courseName;
    }

    public void displayMessage() {
        System.out.printf("Bem vindo ao diario de classe de %s", getCourseName());
    }
}
