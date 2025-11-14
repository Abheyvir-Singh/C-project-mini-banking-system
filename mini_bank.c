#include <stdio.h>
#include <stdlib.h>

struct account {
    int acc_no;
    char name[30];
    float balance;
};

void createAccount() {
    FILE *fp = fopen("bank.txt", "a");
    struct account acc;

    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Account Number: ");
    scanf("%d", &acc.acc_no);
    printf("Enter Name: ");
    scanf("%s", acc.name);
    printf("Enter Initial Balance: ");
    scanf("%f", &acc.balance);

    fprintf(fp, "%d %s %.2f\n", acc.acc_no, acc.name, acc.balance);
    fclose(fp);

    printf("Account Created Successfully!\n");
}

void viewAccounts() {
    FILE *fp = fopen("bank.txt", "r");
    struct account acc;

    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    printf("\n--- Account Details ---\n");
    while (fscanf(fp, "%d %s %f", &acc.acc_no, acc.name, &acc.balance) != EOF) {
        printf("Account No: %d | Name: %s | Balance: %.2f\n", acc.acc_no, acc.name, acc.balance);
    }

    fclose(fp);
}

void depositMoney() {
    struct account acc;
    FILE *fp = fopen("bank.txt", "r");
    FILE *temp=fopen("temp.txt","w");
    int acc_no;
    float amount;
    printf("Enter Account No: ");
    scanf("%d", &acc_no);
    printf("Enter Amount to Deposit: ");
    scanf("%f", &amount);
    printf("Deposited %.2f to Account No %d\n", amount, acc_no);
    while (fscanf(fp,"%d %s %f",&acc.acc_no, acc.name,&acc.balance) != EOF) {
        if(acc.acc_no=acc_no)
        {
            acc.balance=acc.balance+amount;
        }
        fprintf(temp,"%d %s %.2f",acc.acc_no,acc.name,acc.balance);
    }
    fclose(fp);
    fclose(temp);
    remove("bank.txt");
    rename("temp.txt","bank.txt");
}

void withdrawMoney() {
    struct account acc;
    FILE *fp = fopen("bank.txt", "r");
    FILE *temp=fopen("temp.txt","w");
    int acc_no;
    float amount;
    printf("Enter Account No: ");
    scanf("%d", &acc_no);
    printf("Enter Amount to Withdraw: ");
    scanf("%f", &amount);
    printf("Withdrew %.2f from Account No %d\n", amount, acc_no);
    while (fscanf(fp,"%d %s %f",&acc.acc_no, acc.name,&acc.balance) != EOF) {
        if(acc.acc_no=acc_no)
        {
            acc.balance=acc.balance-amount;
        }
        fprintf(temp,"%d %s %.2f",acc.acc_no,acc.name,acc.balance);
    }
    fclose(fp);
    fclose(temp);
    remove("bank.txt");
    rename("temp.txt","bank.txt");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- BANK SYSTEM ---\n");
        printf("1. Create Account\n");
        printf("2. View Accounts\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(); break;
            case 2: viewAccounts(); break;
            case 3: depositMoney(); break;
            case 4: withdrawMoney(); break;
            case 5: exit(0);
        }
    }

    return 0;
}
