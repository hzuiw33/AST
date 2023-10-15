#define _CRT_SECURE_NO_WARNINGS
      
 
void main(void);
void Receipt(int, char);
void Receipt_fin(int, char);
 
int co1 = 50, co2 = 50, co3 = 50, co4 = 50;

int sum = 0, co1_cnt = 0, co2_cnt = 0, co3_cnt = 0, co4_cnt = 0;
int co1_sum = 0, co2_sum = 0, co3_sum = 0, co4_sum = 0;
 

void Finish()
{
    char choice;
 
    printf("Are you sure you want to exit the vending machine program? (End: y, Continue: n)\n");
    printf("Input : ");
    scanf(" %c", &choice);
 
    if (choice == 'y' || choice == 'Y') {
        printf("\n<<Exit the vending machine program. Thank you.>>\n");
 
        
        exit(0);
    }
    else if (choice == 'n' || choice == 'N') {
        printf("\n<<Continue to run the vending machine program.>>\n\n");
 
        main();
    }
    else {
        printf("\n<< You have entered a key that is not in the view. Please select again. >>\n\n");
 
        
        Finish();
    }
}
 

int Admin()
{
    char select;
    int i, coffee, count;
 
    printf("\n");
    for (i = 0; i < 51; i++) {
        printf("=");
    }
    printf("\n\nYou have entered administrator mode.\n\n");
 
   
    printf("======= Coffee stock status =======\n");
    printf("  1. Regular coffee : %d\n  2. Special coffee : %d\n  3. Sugar coffee   : %d\n  4. Black coffee   : %d\n", co1, co2, co3, co4);
    for (i = 0; i < 30; i++) {
        printf("=");
    }
 
    
    printf("\n\nPlease select the function you want..\n");
    printf("1. coffee stocking\n2. Take out coffee stock\n3. Confirmation of the settlement of total\nx. end\n");
    
    
    printf("\n------> Choice : ");
    scanf(" %c", &select);
 
    switch (select) {
    case '1':
        
        printf("\n<< Fill the coffee stock. Please enter the coffee and quantity to recharge the stock. >>\n\n");
        printf("======== Select Menu ========\n");
        printf("    1. Regular coffee\n    2. Special coffee\n    3. Sugar coffee\n    4. Black coffee\n");
        for (i = 0; i < 27; i++) {
            printf("=");
        }
        printf("\n------> Enter coffee number to fill in stock: ");
        scanf("%d", &coffee);
        printf("\n------> Enter quantity to fill inventory: ");
        scanf("%d", &count);
 
        switch (coffee) {
        case 1:
            co1 += count;
 
            break;
        case 2:
            co2 += count;
 
            break;
        case 3:
            co3 += count;
 
            break;
        case 4:
            co4 += count;
 
            break;
        }
 
        break;
    case '2':
       
        printf("\n<< Take the coffee out of stock. Please enter the coffee and quantity to remove the stock. >>\n\n");
        printf("======== Select Menu ========\n");
        printf("    1. Regular coffee\n    2. Special coffee\n    3. Sugar coffee\n    4. Black coffee\n");
        for (i = 0; i < 27; i++) {
            printf("=");
        }
        printf("\n------> Enter coffee number to remove stock: ");
        scanf("%d", &coffee);
        printf("\n------> Enter quantity to subtract inventory: ");
        scanf("%d", &count);
 
        switch (coffee) {
        case 1:
            co1 -= count;
 
            break;
        case 2:
            co2 -= count;
 
            break;
        case 3:
            co3 -= count;
 
            break;
        case 4:
            co4 -= count;
 
            break;
        }
 
        break;
    case '3':
        
        printf("\n<< total sales : %d >>\n\n", sum);
 
        printf("====== Sales by coffee type ======\n");
        printf("  1.   Regular coffee   :   %d\n  2.   Special coffee   :   %d\n  3.   Sugar coffee     :   %d\n  4.   Black coffee     :   %d\n", co1_cnt, co2_cnt, co3_cnt, co4_cnt);
        for (i = 0; i < 32; i++) {
            printf("=");
        }
 
        printf("\n\n====== Sales amount by coffee type ======\n");
        printf("  1.   Regular coffee   :   %d\n  2.   Special coffee   :   %d\n  3.   Sugar coffee     :   %d\n  4.   Black coffee     :   %d\n", co1_sum, co2_sum, co3_sum, co4_sum);
        for (i = 0; i < 35; i++) {
            printf("=");
        }
 
        break;
    case 88:
    case 120:
        printf("\n<< Exits administrator mode. >>\n\n");
        for (i = 0; i < 60; i++) {
            printf("=");
        }
        printf("\n\n");
 
        
        main();
        break;
    default:
        printf("\n<< You have entered a feature that is not in the view. >>\n\n");
 
        
        Admin();
        break;
    }
 
    Admin();
}
 

int Money(int temp)
{
    int money;
 
    while (1)
    {
        printf("\nPut your money in. (You can put in up to 1,000 won in units of 10 won.)\n(Please enter 'x' to exit.)\n");
        printf("Input : ");
        
        if (scanf(" %d", &money) == 0)
        {
            printf("\n");
 
            money = getchar();
            
            if (money == 'x' || money == 'X') {
                printf("<< Take the %d won you put in. >>\n\n", temp);
                rewind(stdin);
                Finish();
            }
            else {
                printf("<< You have entered an invalid character. >>\n\n");
 
                rewind(stdin);
                main();
            }
        }
 
        
        if (money == 920712) {
            Admin(co1, co2, co3, co4);
        }
 
        
        if (money % 10 != 0 || money > 1000) {
            printf("\n<< You have to put in the money in units of 10 won. Please put the money back in. >>\n\n");
 
            continue;
        }
 
        printf("\n");
 
        return money;
    }
}
 

int Start()
{
    int money = 0, i;
 
    while (1)
    {
        printf("Hello.\n This is a coffee machine. (Ver 1.0)\n\n");
        printf("======== Menu & Price ========\n");
        printf("  1. Regular coffee : 300won\n  2. Special coffee : 500won\n  3. Sugar coffee   : 300won\n  4. Black coffee   : 300won\n");
        for (i = 0; i < 29; i++) {
            printf("=");
        }
 
        money = Money(money);    
 
        printf("\n");
 
        return money;
    }
}
 

int Choice(int money, int count)
{
    char menu = '1';
    char available[] = "[Selectable]", Not_available[] = "[Unselectable]";
    char co1_ok[11], co2_ok[11], co3_ok[11], co4_ok[11];
    int plus = 0, price = 0, i;
    
    
    while ('0' < menu && menu < '5')
    {
        
        if (money >= 500) {                    
            strcpy(co1_ok, available);
            strcpy(co2_ok, available);
            strcpy(co3_ok, available);
            strcpy(co4_ok, available);
        }
        else if (money >= 300 && money < 500) {        
            strcpy(co1_ok, available);
            strcpy(co2_ok, Not_available);           
            strcpy(co3_ok, available);
            strcpy(co4_ok, available);
        }
        else if (money < 300) {                        
            strcpy(co1_ok, Not_available);
            strcpy(co2_ok, Not_available);
            strcpy(co3_ok, Not_available);
            strcpy(co4_ok, Not_available);
        }
 
        
        if (co1 < 1)
            strcpy(co1_ok, Not_available);
        if (co2 < 1)
            strcpy(co2_ok, Not_available);
        if (co3 < 1)
            strcpy(co3_ok, Not_available);
        if (co4 < 1)
            strcpy(co4_ok, Not_available);
 
        if (count != 1)
            printf("=== -> Input amount: %d won\n\n", money);       
        else
            printf("=== -> Balance: %d won\n\n", money);        
 
        
        printf("================ Select Menu ================\n");
        printf("   1. Regular coffee : 300won  %s\n   2. Special coffee : 500won  %s\n", co1_ok, co2_ok);
        printf("   3. Sugar coffee   : 300won %s\n   4. Black coffee   : 300won  %s\n", co3_ok, co4_ok);
        for (i = 0; i < 43; i++) {
            printf("=");
        }
 
        
        if (money < 300) {
            printf("\nYou cannot buy coffee with the money you put in.\n");
            plus = Money(money);
            money += plus;        
        }
 
        printf("\nPlease select a menu. (If you want regular coffee, please enter '1'.)\n");
        printf("===-> Input : ");
       
        scanf(" %c", &menu);
        
        
        switch (menu) {
        case '1':
            if (money < 300 || co1 < 1)
                break;
 
            printf("\n=== -> OUTPUT : Regular coffee\n\n");
 
            co1--;
            co1_cnt++;
            co1_sum += 300;
 
            break;
        case '2':
            if (money < 500 || co2 < 1)
                break;
 
            printf("\n=== -> OUTPUT : Special coffee\n\n");
 
            co2--;
            co2_cnt++;
            co2_sum += 500;
 
            break;
        case '3':
            if (money < 300 || co3 < 1)
                break;
 
            printf("\n=== -> OUTPUT : Sugar coffee\n\n");
 
            co3--;
            co3_cnt++;
            co3_sum += 300;
 
            break;
        case '4':
            if (money < 300 || co4 < 1)
                break;
 
            printf("\n=== -> OUTPUT : Black coffee\n\n");
 
            co4--;
            co4_cnt++;
            co4_sum += 300;
 
            break;
        default:
            printf("\n<< You have entered a menu that is not in the view. >>\n\n");
 
            Choice(money, count);
        }
 
        
        if (plus > 0)
        {
            price = menu - 48;
            Receipt_fin(money, price);        
 
            main();        
        }
 
        return menu;
    }
}
 

void Receipt_fin(int money, char menu)
{
    int change, count, price = 0, i;
    char select;
 
    if (menu != '2')
        price = 300;
    else
        price = 500;
 
    sum += price;
    change = money - price;
 
    printf("\n===== a receipt for a receipt =====\n");
    printf("     money entered : %dwon\n", money);
    printf("     Calculated amount  : %dwon\n", price);
    printf("     Change  : %dwon\n", change);
    for (i = 0; i < 28; i++) {
        printf("=");
    }
    
   
    if (change >= 300) {
        printf("\n\nWould you like to buy more coffee with the balance?\n (Please enter 'Y' if you want to purchase or 'N' if you want to return the change without purchasing.)\n");

        printf("Input : ");
        scanf(" %c", &select);
 
        if (select == 'Y' || select == 'y') {
            printf("\n<< Buy more coffee with the balance. >>\n\n");
 
            count = 1;
            menu = Choice(change, count);            
 
            Receipt(change, menu);        
        }
        else if (select == 'N' || select == 'n') {
            printf("\n<< I have returned you the change of %d won. Return to the beginning of the vending machine. >>\n\n", change);
            
            
            rewind(stdin);
            main();
        }
        else {
            printf("\n<< You have entered a key that is not in the view. >>\n\n");
 
            
            Receipt_fin(money, price);
        }
    }
    else {               
        printf("\n\n\n<< The vending machine program has ended. Take the change of %d won. >>\n", change);
        printf("<< Thank you for using. >>");
    }
 
    printf("\n\n");
}
 

void Receipt(int money, char menu)
{
    int i, price, change, plus;
    char select;
 
    
    if (menu == '2')
        price = 500;
    else
        price = 300;
 
    
    change = money - price;
    
    if (change < 0) {        
        printf("\nMoney is scarce. You can buy coffee if you spend more money.\n");
        printf("Would you like to put in more money?\n (Please enter 'Y' if you want additional money or 'N' if you want to end the vending machine.)\n");
        printf("Input : ");
        scanf(" %c", &select);
 
        if (select == 'Y' || select == 'y') {        
            printf("\nPlease put in more money.\n");
            printf("Input : ");
            scanf("%d", &plus);
            money += plus;
        }
        else if (select == 'N' || select == 'n') {           
            printf("\n<<Exit the vending machine program. Take the %d won you put in. >>\n<Thank you for using the vending machine. >>\n\n", money);
 
            
            exit(0);
        }
        else {            
            printf("<< You have entered an invalid character. Take the %d won you put in. >>\n<<< Restart the vending machine program from scratch. >>\n\n", money);
 
            
            rewind(stdin);
            main();
        }
 
        Receipt_fin(money, menu);        
    }
    else {        
       
        if (co1 < 1 || co2 < 1 || co3 < 1 || co4 < 1) {
            printf("\n<< We are sorry, we are out of stock. Please use another coffee>>\n");
            for (i = 0; i < 60; i++) {
                printf("=");
            }
            printf("\n");
 
            main();
        }
 
        Receipt_fin(money, menu);        
    }
 
    printf("\n\n");
}
 
void main()
{
    int money, count = 0;
    char menu;
 
    while (1)
    {
        money = Start();    
        menu = Choice(money, count);        
        Receipt(money, menu);        
    }
 
    return 0;
}
