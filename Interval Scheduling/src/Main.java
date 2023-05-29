import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        List<Meeting> meetings = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);

        System.out.println();
        System.out.println("------- Seja bem vindo(a) ao programa de reuniões! -------");
        System.out.print("Por favor, digite o número de reuniões que deseja adicionar ao programa: ");
        int meetingNumbers = scanner.nextInt();

        System.out.println();

        for (int i = 1; i <= meetingNumbers; i++) {
            System.out.printf("Digite os horários de início e fim da %dº reunião: ", i);
            int startTime = scanner.nextInt();
            int endTime = scanner.nextInt();

            Meeting meeting = new Meeting(i, startTime, endTime);
            meetings.add(meeting);
        }

        System.out.println();

        List<Meeting> selectedMeetings = MeetingScheduler.scheduleMeetings(meetings);

        System.out.println("Melhor alocação para as reuniões informadas: ");

        for (Meeting meeting : selectedMeetings) {
            System.out.println("Reunião " + meeting.number + ", Início: " + meeting.startTime + "h, Fim: " + meeting.endTime + "h");
        }


    }
}