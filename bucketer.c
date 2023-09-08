#include <stdio.h>

struct BatteryCapacity {
    int healthy;
    int exchange;
    int failed;
};

struct BatteryCapacity countBatteriesByHealth(int presentCapacities[], int count) {
    struct BatteryCapacity capacity = {0, 0, 0};

    for (int i = 0; i < count; i++) {
        float soh = (float)presentCapacities[i] / 120.0 * 100.0;
        if (soh >= 80.0) {
            capacity.healthy++;
        } else if (soh < 80.0 && soh >= 65.0) {
            capacity.exchange++;
        } else {
            capacity.failed++;
        }
    }

    return capacity;
}

void testBucketingByHealth() {
    printf("Counting batteries by SoH...\n");
    int presentCapacities[] = {115, 118, 80, 95, 91, 77};
    int count = sizeof(presentCapacities) / sizeof(presentCapacities[0]);
    struct BatteryCapacity counts = countBatteriesByHealth(presentCapacities, count);

    printf("Healthy: %d\n", counts.healthy);
    printf("Exchange: %d\n", counts.exchange);
    printf("Failed: %d\n", counts.failed);

    printf("Done counting :)\n");
}

int main() {
    testBucketingByHealth();
    return 0;
}
