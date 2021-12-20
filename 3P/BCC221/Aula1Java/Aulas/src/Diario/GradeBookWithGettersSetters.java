package Diario;
public class GradeBookWithGettersSetters {
    private String courseName;
    public void setCouseName(String name) {
        courseName = name;
    }
    public String getCourseName() {
        return courseName;
    }

    public void displayMessage() {
        System.out.printf("Curso: %s", getCourseName());
    }
}