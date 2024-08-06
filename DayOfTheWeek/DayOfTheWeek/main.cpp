#include <stdio.h>
#include <string.h>
#include <stdlib.h>

 

void result(int q, int m, int K, int J) {
    int h = (q + ((13 * (m + 1)) / 5) + K + (K / 4) + (J / 4) - (2 * J)) % 7;
    switch (h) {
    case 0:
        printf("Saturday");
        return;
    case 1:
        printf("Sunday");
        return;
    case 2:
        printf("Monday");
        return;
    case 3:
        printf("Tuesday");
        return;
    case 4:
        printf("Wednesday");
        return;
    case 5:
        printf("Thursday");
        return;
    case 6:
        printf("Friday");
        return;
    default:
        printf("BOOOM");
        return;
    }

}

bool isFullFebruary(char input[11]) {
    FILE* file = fopen("path to the full_feb  file", "r");
    char buffer[4];
    if (file == NULL) {
        perror("error opening file!");
        return false;
    }

    while (fgets(buffer, sizeof(buffer), file) != NULL) 
    {               
        if (input[8] == buffer[0] && input[9] == buffer[1]) {
            fclose(file);
           
            return true;
        }
    }
    
    fclose(file);
    return false;
}

bool isDateValid(char input[11]) {
       if (input[0] >= '0' && input[0] <= '3' && input[3] >= '0' && input[3] <= '1') {
        //check if the day is greater than 31
        if (input[0] == '3' && input[1] > '1') {
            return 1;
        }
        //check February for greater than 29
        if (input[3] == '0' && input[4] > '2' && input[0] >= '3') {
            return 1;
        }
        //check months greater than 12
        if (input[3] == '1' && input[4] > '2') {
            return 1;
        }
        //check for full February
        if (isFullFebruary(input)) {
            if (input[0] == '2' && input[1] == '9' && input[3] == '0' && input[4] == '2') {
                return 0;
            }
        }
        else {
            if (input[0] == '2' && input[1] == '9' && input[3] == '0' && input[4] == '2') {
                return 1;
            }
        }

        return 0;
    }

    return 1;
}

int main() {
    int h = -1, q = -1, m = -1;
    char input[11];
    while (true) {
        printf("\nEnter a date: XX.XX.XXXX\n");
        scanf_s("%10s", input, (unsigned)_countof(input));
        while (isDateValid(input)) {
        printf("\nEnter a valid date: XX.XX.XXXX\n");
        scanf_s("%10s", input, (unsigned)_countof(input));
         
        
        }
        for (int i = 0; i < 10; i++) {
            if (input[i] == '.') {
                m += ((input[i - 2] - '0') * 10) + 1;
                m += (input[i - 1] - '0');
            }
            if (q != -1 && m != -1) {
                break;
            }
            if (m != -1) {
                q = m;
                m = -1;
            }
        }
        if (m < 2) {
            m = 13;
            input[9] += '0';
            input[9] -= '1';
        }
        else if (m == 2) {
            m = 14;
            input[9] += '0';
            input[9] -= '1';
        }
        int K = ((input[6] - '0') * 1000 + (input[7] - '0') * 100 + (input[8] - '0') * 10 + input[9] - '0') % 100;
        int J = ((input[6] - '0') * 1000 + (input[7] - '0') * 100 + (input[8] - '0') * 10 + input[9] - '0') / 100;

        result(q, m, K, J);
        memset(input, '\0', sizeof(input));
    }
    return 0;
}