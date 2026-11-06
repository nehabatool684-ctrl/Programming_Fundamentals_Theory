
#include<stdio.h>
//Programmer:Syeda Neha Batool Jaffri
//Section:BDS-1A
//Date: 4-Nov-2026
//purpose:GreenHouse Temperature Monitoring System

void inputData(int rows, int cols, float arr[rows][cols]) {
    for (int r = 0; r < rows; r++) {
        printf("Sensor %d:\n", r + 1);
        for (int c = 0; c < cols; c++) {
            printf("Enter reading %d for sensor %d: ", c + 1, r + 1);
            scanf("%f", &arr[r][c]);
        }
    }
}

// Analyzes ONE sensor (one row) and prints its report
void sensorAnalysis(float arr[], int cols, int sensorNo) {
    float total = 0, max, min;
    int critical = 0, warning = 0;
    int longest = 0, current = 0;

    max = min = arr[0];

    for (int c = 0; c < cols; c++) {
        float t = arr[c];
        total += t;
        if (t > max) max = t;
        if (t < min) min = t;
        if (t >= 40) critical++;
        else if (t >= 35 && t <= 39) warning++;

        if (t >= 35) {
            current++;
            if (current > longest) longest = current;
        } else {
            current = 0;
        }
    }
    float avg = total / cols;
    printf("Sensor %d: Total=%.2f Avg=%.2f Max=%.2f Min=%.2f Critical=%d Warning=%d Longest hot streak=%d\n",
           sensorNo, total, avg, max, min, critical, warning, longest);
}

int highestAverage(int rows, int cols, float arr[rows][cols], float *bestAvg) {
    int bestSensor = 0;
    float maxAvg = -1;
    for (int r = 0; r < rows; r++) {
        float total = 0;
        for (int c = 0; c < cols; c++) total += arr[r][c];
        float avg = total / cols;
        if (avg > maxAvg) {
            maxAvg = avg;
            bestSensor = r;
        }
    }
    *bestAvg = maxAvg;
    return bestSensor + 1; // 1-based sensor number
}

int main() {
    int sensor_count, hourly_readings;
    printf("Enter number of sensors: ");
    scanf("%d", &sensor_count);
    printf("Enter count of hourly readings: ");
    scanf("%d", &hourly_readings);

    float sensor_data[sensor_count][hourly_readings];
    inputData(sensor_count, hourly_readings, sensor_data);

    for (int r = 0; r < sensor_count; r++) {
        sensorAnalysis(sensor_data[r], hourly_readings, r + 1);
    }

    float bestAvg;
    int best = highestAverage(sensor_count, hourly_readings, sensor_data, &bestAvg);
    printf("\nHighest average: Sensor %d (%.2f)\n", best, bestAvg);
    return 0;
}

