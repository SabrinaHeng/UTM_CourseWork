public class Course {
    private CourseCode courseCode;
    private double credit;
    private String description;
    private char grade;

    public enum CourseCode{
        SCSJ2154("Object Oriented Programming",4),
        SCSD2623("Database Programming", 3),
        SCSV1223("Web Programming", 3),
        SCSJ2203("Software Engineering", 3),
        SCSR2043("Operating Systems", 3),
        ULAB2122("Advanced Acedemic English Skills", 2),
        UCSD2762("Fundamentals of Technopreneurship", 2),
        SCSD3761("Technopreneurship Seminar",1);

        private double credit;
        private String description;

        CourseCode(String description, double credit){  //enum's contructior no need private/public
            this.description = description;
            this.credit = credit;
        }

        public String getDescription(){
            return description;
        }

    }

    public Course(String description, double credit){
        this.description = description;
        this.credit = credit;
    }

    public String getDescription(){
        return description;
    }

    public double getCredit(){
        return credit;
    }

    public double getGradeValue(){
        switch(grade){
            case 'A' :
                return 4.0;

            case 'B' :
                return 3.0;

            case 'C' :
                return 2.0;

            case 'D' :
                return 1.0;

            default :
                return 0.0;
        }
    }
}
