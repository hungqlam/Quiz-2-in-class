#include <stdio.h>
#include<stdlib.h>
#include<time.h>
float Meal(float meal, float tax, float tip);
int randomMeal();
int main() {
  
  float total,tax, tip; // take value input from user 
  printf("Enter tax and tip in format X.XX Y.YY:");
  scanf("%f %f", &tax, &tip);
  
  int x = randomMeal(); // random value to select meal
  
  // price per item
  double pSalad = 9.95, pSoup = 4.55, pSandwich = 13.25, pPizza = 22.35;
  
    // switch case for random number
  switch (x) {
    case 1:
        total = Meal(pSalad, tax, tip);
        printf("Salad($%0.2f), tax:%0.2f%%, tip:%0.2f%%, total:$%0.2f .",pSalad,tax,tip,total);
        break;
    case 2:
        total = Meal(pSoup, tax, tip);
        printf("Soup($%0.2f), tax:%0.2f%%, tip:%0.2f%%, total:$%0.2f .",pSoup,tax,tip,total);
        break;
    case 3:
        total = Meal(pSandwich, tax, tip);
        printf("Sandwich($%0.2f), tax:%0.2f%%, tip:%0.2f%%, total:$%0.2f .",pSandwich,tax,tip,total);
        break;
    case 4:
        total = Meal(pPizza, tax, tip);
        printf("Pizza($%0.2f), tax:%0.2f%%, tip:%0.2f%%, total:$%0.2f .",pPizza,tax,tip,total);
        break;
    
    }
    return 0;

}
float Meal(float meal, float tax, float tip)
{
    float total, total1; 
    total = meal* (1+ tax*0.01);
    total1 = total + total*tip*0.01;
    return total1;
}
 int randomMeal()
 {
     int lower = 1, upper = 4;
     srand(time(0));
     int num = (rand() % (upper - lower + 1)) + lower;
     return num;

 }