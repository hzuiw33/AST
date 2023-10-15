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
 
    printf("정말 자판기 프로그램을 종료하시겠습니까? (종료 : y, 계속 실행 : n)\n");
    printf("입력 : ");
    scanf(" %c", &choice);
 
    if (choice == 'y' || choice == 'Y') {
        printf("\n<< 자판기 프로그램을 종료합니다. 감사합니다. >>\n");
 
        
        exit(0);
    }
    else if (choice == 'n' || choice == 'N') {
        printf("\n<< 자판기 프로그램을 계속 실행합니다. >>\n\n");
 
        main();
    }
    else {
        printf("\n<< 보기에 없는 키를 입력하셨습니다. 다시 선택해주십시오. >>\n\n");
 
        
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
    printf("\n\n관리자 모드로 진입하셨습니다.\n\n");
 
   
    printf("======= 커피 재고 현황 =======\n");
    printf("  1. Regular coffee : %d개\n  2. Special coffee : %d개\n  3. Sugar coffee   : %d개\n  4. Black coffee   : %d개\n", co1, co2, co3, co4);
    for (i = 0; i < 30; i++) {
        printf("=");
    }
 
    
    printf("\n\n원하는 기능을 선택해주세요.\n");
    printf("1. 커피 재고 채우기\n2. 커피 재고 빼기\n3. 총 매출 결산 확인\nx. 종료\n");
    
    
    printf("\n------> 선택 : ");
    scanf(" %c", &select);
 
    switch (select) {
    case '1':
        
        printf("\n<< 커피 재고를 채웁니다. 재고를 충전할 커피와 수량을 입력해주세요. >>\n\n");
        printf("======== 메뉴 선택 ========\n");
        printf("    1. Regular coffee\n    2. Special coffee\n    3. Sugar coffee\n    4. Black coffee\n");
        for (i = 0; i < 27; i++) {
            printf("=");
        }
        printf("\n------> 재고를 채울 커피 번호 입력 : ");
        scanf("%d", &coffee);
        printf("\n------> 재고를 채울 수량 입력 : ");
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
       
        printf("\n<< 커피 재고를 뺍니다. 재고를 뺄 커피와 수량을 입력해주세요. >>\n\n");
        printf("======== 메뉴 선택 ========\n");
        printf("    1. Regular coffee\n    2. Special coffee\n    3. Sugar coffee\n    4. Black coffee\n");
        for (i = 0; i < 27; i++) {
            printf("=");
        }
        printf("\n------> 재고를 뺄 커피 번호 입력 : ");
        scanf("%d", &coffee);
        printf("\n------> 재고를 뺄 수량 입력 : ");
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
        
        printf("\n<< 총 매출 : %d원 >>\n\n", sum);
 
        printf("====== 커피 종류별 판매량 ======\n");
        printf("  1.   Regular coffee   :   %d개\n  2.   Special coffee   :   %d개\n  3.   Sugar coffee     :   %d개\n  4.   Black coffee     :   %d개\n", co1_cnt, co2_cnt, co3_cnt, co4_cnt);
        for (i = 0; i < 32; i++) {
            printf("=");
        }
 
        printf("\n\n====== 커피 종류별 판매 금액 ======\n");
        printf("  1.   Regular coffee   :   %d원\n  2.   Special coffee   :   %d원\n  3.   Sugar coffee     :   %d원\n  4.   Black coffee     :   %d원\n", co1_sum, co2_sum, co3_sum, co4_sum);
        for (i = 0; i < 35; i++) {
            printf("=");
        }
 
        break;
    case 88:
    case 120:
        printf("\n<< 관리자 모드를 종료합니다. >>\n\n");
        for (i = 0; i < 60; i++) {
            printf("=");
        }
        printf("\n\n");
 
        
        main();
        break;
    default:
        printf("\n<< 보기에 없는 기능을 입력하셨습니다. >>\n\n");
 
        
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
        printf("\n돈을 투입하세요. (10원 단위로 1000원까지 투입 가능합니다.)\n(종료를 원하시면 'x'를 입력해주세요.)\n");
        printf("투입 : ");
        
        if (scanf(" %d", &money) == 0)
        {
            printf("\n");
 
            money = getchar();
            
            if (money == 'x' || money == 'X') {
                printf("<< 투입하셨던 %d원을 받아가세요. >>\n\n", temp);
                rewind(stdin);
                Finish();
            }
            else {
                printf("<< 잘못된 문자를 입력하셨습니다. >>\n\n");
 
                rewind(stdin);
                main();
            }
        }
 
        
        if (money == 920712) {
            Admin(co1, co2, co3, co4);
        }
 
        
        if (money % 10 != 0 || money > 1000) {
            printf("\n<< 10원 단위로 돈을 투입해주셔야 합니다. 돈을 다시 투입해주세요. >>\n\n");
 
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
        printf("안녕하세요.\n커피 자동 판매기입니다. (Ver 1.0)\n\n");
        printf("======== 메뉴 & 가격 ========\n");
        printf("  1. Regular coffee : 300원\n  2. Special coffee : 500원\n  3. Sugar coffee   : 300원\n  4. Black coffee   : 300원\n");
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
    char available[] = "[선택가능]", Not_available[] = "[선택불가]";
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
            printf("=== -> 투입 금액 : %d원\n\n", money);       
        else
            printf("=== -> 잔액 : %d원\n\n", money);        
 
        
        printf("================ 메뉴 선택 ================\n");
        printf("   1. Regular coffee : 300원  %s\n   2. Special coffee : 500원  %s\n", co1_ok, co2_ok);
        printf("   3. Sugar coffee   : 300원  %s\n   4. Black coffee   : 300원  %s\n", co3_ok, co4_ok);
        for (i = 0; i < 43; i++) {
            printf("=");
        }
 
        
        if (money < 300) {
            printf("\n투입하신 돈으로 커피를 살 수 없습니다.\n");
            plus = Money(money);
            money += plus;        
        }
 
        printf("\n메뉴를 선택해주세요. (Regular coffee를 원한다면 '1'을 입력해주세요.)\n");
        printf("===-> 입력 : ");
       
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
            printf("\n<< 보기에 없는 메뉴를 입력하셨습니다. >>\n\n");
 
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
 
    printf("\n===== 거래 명세 영수증 =====\n");
    printf("     입력한 돈 : %d원\n", money);
    printf("     계산금액  : %d원\n", price);
    printf("     거스름돈  : %d원\n", change);
    for (i = 0; i < 28; i++) {
        printf("=");
    }
    
   
    if (change >= 300) {
        printf("\n\n잔액으로 커피를 더 구매하시겠습니까?\n(구매를 원하시면 'Y', 구매를 하지 않고 거스름돈 반환을 원하시면 'N'을 입력해주세요.)\n");
        printf("입력 : ");
        scanf(" %c", &select);
 
        if (select == 'Y' || select == 'y') {
            printf("\n<< 잔액으로 커피를 더 구매합니다. >>\n\n");
 
            count = 1;
            menu = Choice(change, count);            
 
            Receipt(change, menu);        
        }
        else if (select == 'N' || select == 'n') {
            printf("\n<< 거스름돈 %d원을 반환해드렸습니다. 자판기의 처음 시작으로 돌아갑니다. >>\n\n", change);
            
            
            rewind(stdin);
            main();
        }
        else {
            printf("\n<< 보기에 없는 키를 입력하셨습니다. >>\n\n");
 
            
            Receipt_fin(money, price);
        }
    }
    else {               
        printf("\n\n\n<< 자판기 프로그램이 종료되었습니다. 거스름돈 %d원을 받아가세요. >>\n", change);
        printf("<< 이용해주셔서 감사합니다. >>");
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
        printf("\n돈이 부족합니다. 추가로 돈을 더 투입하시면 커피를 구매하실 수 있습니다.\n");
        printf("추가로 돈을 더 투입하시겠습니까?\n(추가로 돈 투입을 원하시면 'Y', 자판기 종료를 원하시면 'N'을 입력해주세요.)\n");
        printf("입력 : ");
        scanf(" %c", &select);
 
        if (select == 'Y' || select == 'y') {        
            printf("\n돈을 더 투입해주세요.\n");
            printf("투입 : ");
            scanf("%d", &plus);
            money += plus;
        }
        else if (select == 'N' || select == 'n') {           
            printf("\n<< 자판기 프로그램을 종료합니다. 투입했던 %d원을 받아가세요. >>\n<< 자판기를 이용해주셔서 감사합니다. >>\n\n", money);
 
            
            exit(0);
        }
        else {            
            printf("<< 잘못된 문자를 입력하셨습니다. 투입했던 %d원을 받아가세요. >>\n<< 자판기 프로그램을 처음부터 다시 시작합니다. >>\n\n", money);
 
            
            rewind(stdin);
            main();
        }
 
        Receipt_fin(money, menu);        
    }
    else {        
       
        if (co1 < 1 || co2 < 1 || co3 < 1 || co4 < 1) {
            printf("\n<< 죄송합니다. 재고가 없습니다. 다른 커피를 이용해주세요. >>\n");
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
