import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class MeetingScheduler {

    public static List<Meeting> scheduleMeetings(List<Meeting> meetings) {
        List<Meeting> selectedMeetings = new ArrayList<>();

        //Ordena as reuniões em ordem crescente de horário de término
        meetings.sort(Comparator.comparingInt(m -> m.endTime));

        // Seleciona a primeira reunião
        if (!meetings.isEmpty()) {
            selectedMeetings.add(meetings.get(0));
            int lastEndTime = meetings.get(0).endTime;

            // Percorre as reuniões restantes
            for (int i = 1; i < meetings.size(); i++) {
                Meeting currentMeeting = meetings.get(i);

                // Verifica se a reunião não entra em conflito com as já selecionadas
                if (currentMeeting.startTime >= lastEndTime) {
                    selectedMeetings.add(currentMeeting);
                    lastEndTime = currentMeeting.endTime;
                }
            }
        }

        return selectedMeetings;
    }
}