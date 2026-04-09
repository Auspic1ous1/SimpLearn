#include <stdio.h>
#include <string.h>

int main() {
    int x = 0;
    int y = 0;
    int z = 0;
    int result = 0;
    int counter = 0;
    int limit = 0;
    float temperature = 0;
    float avg = 0;
    float pi = 0;
    char name[256] = "";
    char greeting[256] = "";
    char message[256] = "";
    char city[256] = "";
    char country[256] = "";
    printf("%d\n", 1000);
    printf("%s\n", "=== STRING TESTS ===");
    printf("%s\n", "Hello, World!");
    printf("%s\n", "Testing string literals");
    strcpy(name, "Alice");
    printf("%s\n", name);
    strcpy(greeting, "Good Morning!");
    printf("%s\n", greeting);
    strcpy(message, "Welcome to Simplearn");
    printf("%s\n", message);
    strcpy(city, "Mumbai");
    strcpy(country, "India");
    printf("%s\n", city);
    printf("%s\n", country);
    printf("%s\n", "Enter your name:");
    if (fgets(name, 256, stdin)) {
        name[strcspn(name, "\n")] = 0;
    }
    printf("%s\n", "Hello");
    printf("%s\n", name);
    printf("%s\n", "Enter your city:");
    if (fgets(city, 256, stdin)) {
        city[strcspn(city, "\n")] = 0;
    }
    printf("%s\n", "You are from");
    printf("%s\n", city);
    printf("%d\n", 2000);
    x = 10;
    y = 20;
    z = 5;
    printf("%d\n", x);
    printf("%d\n", y);
    printf("%d\n", z);
    result = (x+y);
    printf("%d\n", result);
    result = (y-z);
    printf("%d\n", result);
    result = (x*z);
    printf("%d\n", result);
    result = (y/z);
    printf("%d\n", result);
    result = (y%z);
    printf("%d\n", result);
    result = (((x+y)*z)-10);
    printf("%d\n", result);
    result = (x+((y*z)/2));
    printf("%d\n", result);
    result = (-x);
    printf("%d\n", result);
    printf("%d\n", 3000);
    temperature = 25.500000;
    avg = 100.000000;
    pi = 3.141590;
    printf("%f\n", (float)temperature);
    printf("%f\n", (float)avg);
    printf("%f\n", (float)pi);
    avg = (temperature+10.500000);
    printf("%f\n", (float)avg);
    printf("%d\n", 4000);
    printf("%s\n", "Enter an integer:");
    scanf("%d", &counter);
    getchar();
    printf("%s\n", "You entered:");
    printf("%d\n", counter);
    printf("%s\n", "Enter a float:");
    scanf("%f", &temperature);
    getchar();
    printf("%s\n", "You entered:");
    printf("%f\n", (float)temperature);
    printf("%d\n", 5000);
    if ((x > 5)) {
    printf("%d\n", 5001);
    }
    if ((y > 30)) {
    printf("%d\n", 5002);
    } else {
    printf("%d\n", 5003);
    }
    if ((counter > 0)) {
    printf("%s\n", "Positive number");
    if ((counter > 10)) {
    printf("%s\n", "Large positive");
    } else {
    printf("%s\n", "Small positive");
    }
    } else {
    printf("%s\n", "Non-positive");
    }
    if (((counter > 5) && (counter < 15))) {
    printf("%d\n", 5004);
    }
    if (((counter < 0) || (counter > 100))) {
    printf("%d\n", 5005);
    }
    if ((!(counter == 0))) {
    printf("%d\n", 5006);
    }
    if ((x == 10)) {
    printf("%d\n", 5101);
    }
    if ((y != x)) {
    printf("%d\n", 5102);
    }
    if ((y > x)) {
    printf("%d\n", 5103);
    }
    if ((x < y)) {
    printf("%d\n", 5104);
    }
    if ((y >= 20)) {
    printf("%d\n", 5105);
    }
    if ((x <= 10)) {
    printf("%d\n", 5106);
    }
    printf("%d\n", 6000);
    counter = 1;
    limit = 5;
    while ((counter <= limit)) {
    printf("%d\n", counter);
    counter = (counter+1);
    }
    counter = 3;
    while ((counter > 0)) {
    printf("%s\n", "Countdown:");
    printf("%d\n", counter);
    counter = (counter-1);
    }
    x = 2;
    while ((x <= 3)) {
    y = 1;
    while ((y <= 2)) {
    result = ((x*10)+y);
    printf("%d\n", result);
    y = (y+1);
    }
    x = (x+1);
    }
    printf("%d\n", 7000);
    for (counter=1; counter<=5; counter+=1) {
    printf("%d\n", counter);
    }
    for (counter=0; counter<=10; counter+=2) {
    printf("%d\n", counter);
    }
    for (counter=5; counter<=20; counter+=5) {
    printf("%d\n", counter);
    }
    for (counter=1; counter<=3; counter+=1) {
    printf("%s\n", "Iteration:");
    printf("%d\n", counter);
    }
    printf("%d\n", 8000);
    for (x=1; x<=3; x+=1) {
    if ((x == 2)) {
    printf("%s\n", "Special case: x = 2");
    y = 1;
    while ((y <= 3)) {
    printf("%d\n", y);
    y = (y+1);
    }
    } else {
    printf("%s\n", "Regular case:");
    printf("%d\n", x);
    }
    }
    x = 10;
    y = 20;
    z = 5;
    result = ((((x+y)*(z-1))/2)+7);
    printf("%d\n", result);
    counter = 15;
    if (((counter > 10) && (counter < 20))) {
    printf("%s\n", "Range 10-20");
    if ((counter == 15)) {
    printf("%s\n", "Exactly 15");
    }
    } else {
    printf("%s\n", "Outside range");
    }
    printf("%d\n", 9000);
    x = 42;
    temperature = 98.599998;
    strcpy(name, "Result");
    printf("%s\n", "Integer:");
    printf("%d\n", x);
    printf("%s\n", "Float:");
    printf("%f\n", (float)temperature);
    printf("%s\n", "String:");
    printf("%s\n", name);
    result = (x+8);
    printf("%d\n", result);
    avg = (temperature-0.600000);
    printf("%f\n", (float)avg);
    printf("%d\n", 10000);
    x = 0;
    printf("%d\n", x);
    if ((x == 0)) {
    printf("%s\n", "Zero detected");
    }
    y = (-42);
    printf("%d\n", y);
    strcpy(message, "");
    printf("%s\n", "Empty string test:");
    printf("%s\n", message);
    strcpy(greeting, "This is a very long string to test buffer handling");
    printf("%s\n", greeting);
    x = 100;
    y = 50;
    z = 25;
    result = ((x-y)+(z*2));
    printf("%s\n", "Final result:");
    printf("%d\n", result);
    printf("%s\n", "=== ALL TESTS COMPLETED ===");
    printf("%d\n", 99999);
    return 0;
}
