#include <stdio.h>
#include <assert.h>

struct CountsBySoH {
  int healthy;
  int exchange;
  int failed;
};

struct CountsBySoH countBatteriesByHealth(const int* presentCapacities, int nBatteries) {
  struct CountsBySoH counts = {0, 0, 0};
 for (int i = 0; i < nBatteries; i++) {
    // Calculate SoH for each battery
    double presentCapacity = static_cast<double>(presentCapacities[i]);
    double ratedCapacity = 120.0; // Rated capacity of a new battery

    double SoH = (presentCapacity / ratedCapacity) * 100.0;

    // Classify the battery based on SoH and update counts
    if (SoH > 100.0) {
      counts.healthy++;
    } else if (SoH >= 65.0 && SoH <= 80.0) {
      counts.exchange++;
    } else {
      counts.failed++;
    }
  }
  return counts;
}

void testBucketingByHealth() {
   int capacities1[] = {105, 90, 120, 55, 70};
  struct CountsBySoH result1 = countBatteriesByHealth(capacities1, 5);
  assert(result1.healthy == 2);
  assert(result1.exchange == 1);
  assert(result1.failed == 2);

  int capacities2[] = {130, 115, 70, 50};
  struct CountsBySoH result2 = countBatteriesByHealth(capacities2, 4);
  assert(result2.healthy == 2);
  assert(result2.exchange == 1);
  assert(result2.failed == 1);

  int capacities3[] = {120, 120, 120};
  struct CountsBySoH result3 = countBatteriesByHealth(capacities3, 3);
  assert(result3.healthy == 3);
  assert(result3.exchange == 0);
  assert(result3.failed == 0);
    
}

int main() {
  testBucketingByHealth();
  return 0;
}
