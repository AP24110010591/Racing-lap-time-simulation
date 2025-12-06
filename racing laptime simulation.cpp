#include <stdio.h>
#define MAX_RACERS 10
#define MAX_LAPS 50
int main() {
    int racers, laps;
    double lapTime[MAX_RACERS][MAX_LAPS];
    double totalTime[MAX_RACERS];
    double bestLapRacer[MAX_RACERS];

    printf("=== RACING LAP TIME SIMULATION ===\n");

    printf("Enter number of racers (max %d): ", MAX_RACERS);
    scanf("%d", &racers);
    if (racers < 1 || racers > MAX_RACERS) {
        printf("Invalid number of racers.\n");
        return 0;
    }
    printf("Enter number of laps (max %d): ", MAX_LAPS);
    scanf("%d", &laps);
    if (laps < 1 || laps > MAX_LAPS) {
        printf("Invalid number of laps.\n");
        return 0;
    }
    for (int i = 0; i < racers; i++) {
        printf("\n--- Enter lap times for Racer %d ---\n", i + 1);
        for (int j = 0; j < laps; j++) {
            printf("Lap %2d time (in seconds): ", j + 1);
            scanf("%lf", &lapTime[i][j]);
        }
    }

    double fastestLap = -1.0;
    int fastestRacer = -1;
    int fastestLapNo = -1;

    for (int i = 0; i < racers; i++) {
        totalTime[i] = 0.0;
        bestLapRacer[i] = lapTime[i][0];

        for (int j = 0; j < laps; j++) {
            double t = lapTime[i][j];
            totalTime[i] += t;

            if (t < bestLapRacer[i]) {
                bestLapRacer[i] = t;
            }

            if (fastestLap < 0 || t < fastestLap) {
                fastestLap = t;
                fastestRacer = i;
                fastestLapNo = j;
            }
        }
    }

    int winner = 0;
    for (int i = 1; i < racers; i++) {
        if (totalTime[i] < totalTime[winner]) {
            winner = i;
        }
    }

    printf("\n========== RACE SUMMARY ==========\n");
    for (int i = 0; i < racers; i++) {
        printf("Racer %d: Total Time = %.2f s, Best Lap = %.2f s\n",
               i + 1, totalTime[i], bestLapRacer[i]);
    }

    printf("\nOverall fastest lap: Racer %d, Lap %d, Time = %.2f s\n",
           fastestRacer + 1, fastestLapNo + 1, fastestLap);

    printf("Winner (least total time): Racer %d (%.2f s)\n",
           winner + 1, totalTime[winner]);

    printf("\nLap-wise details:\n");
    for (int i = 0; i < racers; i++) {
        printf("Racer %d laps: ", i + 1);
        for (int j = 0; j < laps; j++) {
            printf("%.2f ", lapTime[i][j]);
        }
        printf("\n");
    }

    return 0;
}
