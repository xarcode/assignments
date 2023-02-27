import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class HolidayList {
    public static void main(String[] args) {
        List<LocalDate> holidays = new ArrayList<>();
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd-MM-yyyy");

        holidays.add(LocalDate.parse("26-01-2023", formatter));
        holidays.add(LocalDate.parse("04-03-2023", formatter));
        holidays.add(LocalDate.parse("15-08-2023", formatter));
        holidays.add(LocalDate.parse("27-10-2023", formatter));

        
        LocalDate myBirthday = LocalDate.parse("31-03-2023", formatter);
        holidays.add(myBirthday);        
        Collections.sort(holidays);

        System.out.println("Sorted list of holidays:");
        for (LocalDate holiday : holidays) {
            System.out.println(formatter.format(holiday));
        }
    }
}
