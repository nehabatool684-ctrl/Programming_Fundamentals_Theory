#include <stdio.h>

int input(int row, int col, int sensor_array[row][col]);
void sensorAnalysis(int row, int col, int sensor_array[row][col]);
int highestAverage(int row, int col, int sensor_array[row][col], int k, int *foundRow, int *foundStart);

int main() {
    int hourly_readings = 0;
    int sensor_count = 0;

    printf("Enter number of sensors");
    scanf("%d", &sensor_count);

    printf("enter count of hourly reading");
    scanf("%d", &hourly_readings);

    int sensor_data[sensor_count][hourly_readings];

    input(sensor_count, hourly_readings, sensor_data);
    sensorAnalysis(sensor_count, hourly_readings, sensor_data);

    int k;
    printf("Enter group size k: ");
    scanf("%d", &k);

    while (k <= 0 || k > hourly_readings) {
        printf("Invalid! k must be > 0 and <= %d. Enter again: ", hourly_readings);
        scanf("%d", &k);
    }

    int foundRow = -99, foundStart = -99;
    int success = highestAverage(sensor_count, hourly_readings, sensor_data, k, &foundRow, &foundStart);

    if (success) {
        printf("Group of %d seated in Row %d, Seats %d to %d\n\n",
               k, foundRow, foundStart, foundStart + k - 1);
    } else {
        printf("No %d consecutive seats available.\n\n", k);
    }

    // Display again 
    printf("    ");
    for (int col = 0; col < hourly_readings; col++) {
        printf("%d ", col);
    }
    printf("\n");
    for (int row = 0; row < sensor_count; row++) {
        printf("R%d  ", row);
        for (int col = 0; col < hourly_readings; col++) {
            if (sensor_data[row][col] == 0) printf("_ ");
            else printf("X ");
        }
        printf("\n");
    }

    return 0;
}

int input(int row, int col, int sensor_array[row][col]) {
    printf("Enter seating status (0 = free, 1 = booked):\n");
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            scanf("%d", &sensor_array[r][c]);
        }
    }
    return 0;
}

void sensorAnalysis(int row, int col, int sensor_array[row][col]) {
    int total = 0;
    printf("Free seats per row: ");
    for (int r = 0; r < row; r++) {
        int count = 0;
        for (int c = 0; c < col; c++) {
            if (sensor_array[r][c] == 0) count++;
        }
        printf("%d ", count);
        total += count;
    }
    printf(" Total free: %d\n\n", total);
}

int highestAverage(int row, int col, int sensor_array[row][col], int k, int *foundRow, int *foundStart) {
    int mid = row / 2;

    for (int dist = 0; dist < row; dist++) {
        int rowsToCheck[2];
        int n = 0;
        if (dist == 0) {
            rowsToCheck[n++] = mid;
        } else {
            if (middle - dist >= 0) rowsToCheck[n++] = mid - dist;
            if (middle + dist < row) rowsToCheck[n++] = mid + dist;
        }

        for (int r = 0; r < n; r++) {
            int currentRow = rowsToCheck[r];
            int consecutive = 0;
            for (int c = 0; c < col; c++) {
                if (sensor_array[currentRow][c] == 0) {
                    consecutive++;
                    if (consecutive == k) {
                        *foundRow = currentRow;
                        *foundStart = c - k + 1;
                        for (int s = *foundStart; s < *foundStart + k; s++) {
                            sensor_array[currentRow][s] = 1;
                        }
                        return 1;
                    }
                } 
				else {
                    consecutive = 0;
                }
            }
        }
    }
    return 0;
}
