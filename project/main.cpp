#include<iostream>
#include<cstdio>
#include<fstream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<conio.h>
#include<windows.h>
#include<mysql.h>

  using namespace std;

// Global Variable
MYSQL* conn;
MYSQL_ROW row;
MYSQL_RES* res;
int qstate;
// Global Variable End
// Extra Functions CodeWithC


// Fucntions

void Welcome() ;

void BuyMedicine(string);
int buyin () ;

void ShowItemList(string); // show items in each specification
int showin () ; // show the products list

int findin (); // which database you want to add or find
void FindItemFromList(string);

void AddIteminStock(string);
int addin() ;

void UpdateStockItem(string);
int updatein() ;

void DeleteStockItem(string);
int deletein () ;

void users() ;
int menu () ;


// public variables: username and password for users function

string username = "";
string password = "";
string usernamecheck = "";
string passwordcheck = "";






int main()
{
    system ("cls") ;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", "root", "", "koko", 0, NULL, 0);
    if(conn){
        cout << "connecting database successfully ^-^\n";
        getch() ;
    users() ;
    menu() ;
            }
    else{
        cout << "Connection Error/n" << endl;
    }

    return 0;
}




void Welcome() {
    cout << username << endl << endl;
}

void users () {

    system("cls");
    cout << "please enter your user name and password" << endl << "user name: " ;
    getline(cin , usernamecheck) ;
    cout << endl << "password: " ;
    getline(cin , passwordcheck);
    string username_query = "select * from user where username like '"+usernamecheck+"' and password like '"+passwordcheck+"' ";
    const char* qn = username_query.c_str();
    qstate = mysql_query(conn, qn);  //return 0 if success

    res = mysql_store_result(conn);

    if (!qstate){

    while ((row = mysql_fetch_row(res)))
        {

        username = row[0] ;
        password = row [1] ;
        system ("cls");
        cout << endl << "welcom: " << username << endl << endl ;


        }

    }else {
            cout << "/nquery error"  ;
    }
            if (username != usernamecheck && password != passwordcheck) {

            system("cls") ;
            cout << endl << "username or password isn't true, \n" ;
            users() ;
                }

}



int menu() {

         string chooseOneFromMenuString = "0" ; //for functions

        cout << "what are you interesting in , please chose a number from the menu: " << endl ;
        cout << " 1. Buy Medicine" << endl;
        cout << " 2. Show Item List" << endl;
        cout << " 3. Find Item From List" << endl;
        cout << " 4. Add Item in Stock" << endl;
        cout << " 5. Update Stock Item" << endl;
        cout << " 6. Delete Stock Item" << endl;
        cout << " 7. Exit" << endl;
        cout << " 8. logout" << endl;


    cin >> chooseOneFromMenuString;
    int  chooseOneFromMenu  ;
    stringstream(chooseOneFromMenuString) >> chooseOneFromMenu ;
    char exitSurity;

   switch (chooseOneFromMenu){
        case 1:
            buyin();
            break;
        case 2:
            showin();
            break;
        case 3:
            findin();
            break;
        case 4:
            addin();
            break;
        case 5:
            updatein();
            break;
        case 6:
            deletein();
            break;

        case 7:
            ExitProgram:
            cout << "Program terminating, Are you sure? (y/N): ";
            cin >> exitSurity;
            if (exitSurity == 'y' || exitSurity == 'Y') {
                return 0;
            }else if (exitSurity == 'n' || exitSurity == 'N') {
                system("cls");
                main();
            }else {
                cout << "Next time choose after read the corresponding line." << endl;
                goto ExitProgram;
            }

            break;

         case 8:
            logout:
            cout << "logout, Are you sure? (y/N): ";
            cin >> exitSurity;
            if (exitSurity == 'y' || exitSurity == 'Y') {
                return 0;
            }else if (exitSurity == 'n' || exitSurity == 'N') {
                system("cls");
                menu();
            }else {
                cout << "Next time choose after read the corresponding line." << endl;
                goto logout;
            }
            break;

        default:
            cout << "Please choose between 1 - 7. Press Enter To Continue...";
            getch();
            system("cls");
            menu();
            break;
    }




    return 0 ;
}


//------------------------------------------------------------------------

// functions



int buyin ()  // show product tables
{
    string chooseOneFromMenuString = "0" ;

    cout << "which product do you want to buy: " ;
    cout << "\nmedicine product: " << endl ;
        cout << "      1. creams" << endl;
        cout << "      2. lution" << endl;
        cout << "      3. syrup" << endl;
        cout << "      4. tablets"  << endl;
        cout << "      5. capsule" << endl;
        cout << "      6. injection" << endl;
        cout << "      7. soultion" << endl;
printf("   ---------------------\n");
    cout << "\n cosmetic: " << endl ;
        cout << "      8. Lipstick" << endl;
        cout << "      9. Primer" << endl;
        cout << "      10. Concealer" << endl;
        cout << "      11. Foundation"  << endl;
        cout << "      12. Face powder" << endl;
        cout << "      13. Rouge, blush, or blusher" << endl;
        cout << "      14. Highlight" << endl;
        cout << "      15. Bronzer" << endl;
        cout << "      16. Mascara" << endl;
        cout << "      17. Eye shadow"  << endl;
        cout << "      18. Eye liner" << endl;
 printf("   ---------------------\n");
        cout << "\n healthy product: " << endl ;
        cout << "      19. Tooth paste" << endl;
        cout << "      20. shampoo" << endl;
        cout << "      21. hair cream" << endl;
        cout << "      22. face cream"  << endl;
printf("   ---------------------\n");
        cout << "\n control: " << endl ;
        cout << "      23. main menu" << endl;
        cout << "      24. logout" << endl;
        cout << "      25. exit" << endl;


    cin >> chooseOneFromMenuString;
    int  chooseOneFromMenu;
    stringstream(chooseOneFromMenuString) >> chooseOneFromMenu ;
    char exitSurity;

   switch (chooseOneFromMenu){
        case 1:
            BuyMedicine("creams");
        break;

        case 2:
            BuyMedicine("lutions");
        break;

        case 3:
            BuyMedicine("syrup");
        break;

        case 4:
            BuyMedicine("tablets");
        break;

        case 5:
            BuyMedicine("capsule");
        break;

        case 6:
            BuyMedicine("injection");
        break;

        case 7:
            BuyMedicine("solution");
        break;

        case 8:
            BuyMedicine("Lipstick");
        break;

        case 9:
            BuyMedicine("Primer");
        break;

        case 10:
            BuyMedicine("Concealer");
        break;

        case 11:
            BuyMedicine("Foundation");
        break;

        case 12:
            BuyMedicine("Facepowder");
        break;

        case 13:
            BuyMedicine("Rouge");
        break;

        case 14:
            BuyMedicine("Highlight");
        break;

        case 15:
            BuyMedicine("Bronzer");
        break;

        case 16:
            BuyMedicine("Mascara");
        break;

        case 17:
            BuyMedicine("Eyeshadow");
        break;

        case 18:
            BuyMedicine("Eyeliner");
        break;

        case 19:
           BuyMedicine("Toothpaste");
        break;

        case 20:
            BuyMedicine("shampoo");
        break;

        case 21:
            BuyMedicine("haircream");
        break;

        case 22:
            BuyMedicine("facecream");
        break;

        case 23:
            menu();
        break;



        case 24:
            ExitProgram:
            cout << "Program terminating, Are you sure? (y/N): ";
            cin >> exitSurity;
            if (exitSurity == 'y' || exitSurity == 'Y') {
                return 0;
            }else if (exitSurity == 'n' || exitSurity == 'N') {
                system("cls");
                buyin();
            }else {
                cout << "Next time choose after read the corresponding line." << endl;
                goto ExitProgram;
            }

            break;

         case 25:
             logout:
             cout << "logout, Are you sure? (y/N): ";
            cin >> exitSurity;
            if (exitSurity == 'y' || exitSurity == 'Y') {
                return 0;
            }else if (exitSurity == 'n' || exitSurity == 'N') {
                system("cls");
                buyin();
            }else {
                cout << "Next time choose after read the corresponding line." << endl;
                goto logout;
            }
            break;
        default:
            cout << "Please choose between 1 - 25. Press Enter To Continue...";
            getch();
            system("cls");
            buyin();
            break;
    }
}






void BuyMedicine(string product) {
    //system("cls");

    // Variables
    string choose = "";

    string getId = "";// id you want to buy
    string itemId[5000]="";
    string itemName[5000]="";
    string chooseEditOrBuy =""; //for editing or buy
    int itemIndex = 0;
	float totalPrice = 0.0;
    bool purchase, itemFalse = false;

    string storeid[5000] = "";
    string storename[5000] = "";
    string storecompany[5000] = "";
    string storearrival_date[5000]="";
    string storeexpire_date[5000]="";
    string storeprice[5000]="";
    string storequantity[5000]="";
    int storeIndex = 0, //index for array

	storeIndexN = 0;

    // Variables End

    Welcome();

    string buy_query = "select * from " + product ;
    const char * qn = buy_query.c_str() ;
    qstate = mysql_query(conn, qn );
    if (!qstate)
    {
        res = mysql_store_result(conn);
        printf("---------------------------------------------------------------------------------------------------------\n");
        printf("| %-10s | %-15s | %-15s | %-15s | %-15s | %-5s | %-8s |\n", "Column Id", "Name", "Company", "Arrival Date", "Expire Date", "Price", "Quantity");
        printf("---------------------------------------------------------------------------------------------------------\n");
        while ((row = mysql_fetch_row(res)))
        {
            if (atoi(row[6]) > 0)
            {
                printf("| %-10s | %-15s | %-15s | %-15s | %-15s | %-5s | %-8s |\n", row[0], row[1], row[2], row[3], row[4], row[5], row[6]);

                storeid[storeIndex] = row[0];
                storename[storeIndex] = row[1];
                storecompany[storeIndex] = row[2];
                storearrival_date[storeIndex] = row[3];
                storeexpire_date[storeIndex] = row[4];
                storeprice[storeIndex] = row[5];
                storequantity[storeIndex] = row[6];
                storeIndex++;
            }
        }
        printf("---------------------------------------------------------------------------------------------------------\n");
    }

    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }



    for (itemIndex = 0; ;itemIndex++)
    {
        cout << "Enter a Column ID's (q to exit): ";
        cin >> getId;
        if (getId == "q" || getId == "Q")
        {
            break;
        }


        else
        {
            for(int i = 0; i < storeIndex; i++)
            {
                if (getId == storeid[i])
                {
                    itemId[itemIndex] = getId;
                    itemFalse = false;
				   break;
                }
                else
                {
                    itemFalse = true;
                }
            }


            if (itemFalse == true)
            {
                cout << "Enter a valid number." << endl;
                itemIndex--;
                itemFalse = false;
            }
        }
    }

// showing the buying list
if (itemIndex == 0){
    cout << " you didn't buy anything";
    goto exitcode;
}else{
    cout<< "you choose this items:\n";
}
    for (int i = 0; i < itemIndex; i++)
    {
        cout << itemId[i] << endl ;
    }


    // edit the list or confirm
    CHOOSEEDITORBUY:
    cout << endl << "Do you want to edit items(e) or buy this items(b): \n hint press 'e' for edit or 'b' for buy ";
    cin >> chooseEditOrBuy;

    if (chooseEditOrBuy == "e" || chooseEditOrBuy == "E" )
    {
        for (int i = 0;;i++)
        {
            cout << "Remove item id's (q to exit): ";
            cin >> getId;
            if (getId == "q")
            {
                break;
            }else
            {
                for (int j = 0;j < itemIndex;j++)
                {
                    if (itemId[j] == getId)
                    {
                        for (int k = j; k < itemIndex; k++)
                        {
                            itemId[k] = itemId[k+1];
                        }
                        itemId[itemIndex--] = "\0";
                    }
                }
            }
        }



        cout << "You choose this song id's: ";
        for (int i = 0; i < itemIndex; i++)
        {
            cout << endl << itemId[i] << " ";
        }

        goto CHOOSEEDITORBUY;
    }


    else if (chooseEditOrBuy == "b" || chooseEditOrBuy == "B")
    {
        for (int i = 0; i < itemIndex; i++)
        {
            for (int j = 0 ; j < storeIndex; j++)
            {
                if (itemId[i] == storeid[j])
                {
                    buy_query = "select quantity from " + product ;
                    qn = buy_query.c_str() ;
                    qstate = mysql_query(conn, qn);
                    if (!qstate)
                    {
                        res = mysql_store_result(conn);
                        while ((row = mysql_fetch_row(res)))
                        {
                            if (atoi(row[0]) > 0)
                            {
                                storequantity[storeIndexN] = row[0];
                                storeIndexN++;
                            }
                        }

                        storeIndexN = 0;
                    }else
                    {
                        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
                    }


                    totalPrice += strtof((storeprice[j]).c_str(), 0);

                    float quan1 = strtof((storequantity[j]).c_str(), 0);
                    quan1 -= 1;


                    string getQuan1;
                    stringstream strquan1;
                    strquan1 << quan1;
                    strquan1 >> getQuan1;


                    purchase = true;

                    string update_query = "update " + product + " set quantity = '"+getQuan1+"' where id = '"+storeid[j]+"'";
                    const char* qu = update_query.c_str();
                    qstate = mysql_query(conn, qu);

                    if (qstate)
                    {

                        cout << "Failed To Update!" << mysql_errno(conn) << endl;
                    }
                }
            }
        }



        if(purchase == true)
        {
            cout << endl << "Purchase Successfully Done." << endl;
            cout << endl << "Total Price: " << totalPrice << endl;
        }
    } else {
        cout << "/n wrong choose /n" ; goto CHOOSEEDITORBUY ;
    }




  exitcode:
    // Exit Code
    cout << endl << "Press 'm' to Menu, 'a' to purchase again and 'e' to Exit: ";
    cin >> choose;
    if (choose == "m" || choose == "M")
    {
        system("cls") ;
        main();
    }

    else if (choose == "a" || choose == "A")
    {
        system("cls");;
        BuyMedicine(product);
    }
    else if (choose == "a" || choose == "A")
    {
        exit(0);
    }

    else
    {
        cout << " please read the next line well " << endl  ;
        goto exitcode;
    }
}







int showin ()  // show product tables
{
    string chooseOneFromMenuString = "0" ;

    cout << "\nmedicine product: " << endl ;
        cout << "      1. creams" << endl;
        cout << "      2. lutions" << endl;
        cout << "      3. syrup" << endl;
        cout << "      4. tablets"  << endl;
        cout << "      5. capsule" << endl;
        cout << "      6. injection" << endl;
        cout << "      7. solution" << endl;
printf("   ---------------------\n");
    cout << "\n cosmetic: " << endl ;
        cout << "      8. Lipstick" << endl;
        cout << "      9. Primer" << endl;
        cout << "      10. Concealer" << endl;
        cout << "      11. Foundation"  << endl;
        cout << "      12. Face powder" << endl;
        cout << "      13. Rouge, blush, or blusher" << endl;
        cout << "      14. Highlight" << endl;
        cout << "      15. Bronzer" << endl;
        cout << "      16. Mascara" << endl;
        cout << "      17. Eye shadow"  << endl;
        cout << "      18. Eye liner" << endl;
 printf("   ---------------------\n");
        cout << "\n healthy product: " << endl ;
        cout << "      19. Tooth paste" << endl;
        cout << "      20. shampoo" << endl;
        cout << "      21. hair cream" << endl;
        cout << "      22. face cream"  << endl;
printf("   ---------------------\n");
        cout << "\n control: " << endl ;
        cout << "      23. main menu" << endl;
        cout << "      24. logout" << endl;
        cout << "      25. exit" << endl;


    cin >> chooseOneFromMenuString;
    int  chooseOneFromMenu;
    stringstream(chooseOneFromMenuString) >> chooseOneFromMenu ;

    char exitSurity;

   switch (chooseOneFromMenu){
        case 1:
            ShowItemList("creams");
        break;

        case 2:
            ShowItemList("lutions");
        break;

        case 3:
            ShowItemList("syrup");
        break;

        case 4:
            ShowItemList("tablets");
        break;

        case 5:
            ShowItemList("capsule");
        break;

        case 6:
            ShowItemList("injection");
        break;

        case 7:
            ShowItemList("solution");
        break;

        case 8:
            ShowItemList("Lipstick");
        break;

        case 9:
            ShowItemList("Primer");
        break;

        case 10:
            ShowItemList("Concealer");
        break;

        case 11:
            ShowItemList("Foundation");
        break;

        case 12:
            ShowItemList("Facepowder");
        break;

        case 13:
            ShowItemList("Rouge");
        break;

        case 14:
            ShowItemList("Highlight");
        break;

        case 15:
            ShowItemList("Bronzer");
        break;

        case 16:
            ShowItemList("Mascara");
        break;

        case 17:
            ShowItemList("Eyeshadow");
        break;

        case 18:
            ShowItemList("Eyeliner");
        break;

        case 19:
            ShowItemList("Toothpaste");
        break;

        case 20:
            ShowItemList("shampoo");
        break;

        case 21:
            ShowItemList("haircream");
        break;

        case 22:
            ShowItemList("facecream");
        break;

        case 23:
            menu();
        break;



        case 24:
            ExitProgram:
            cout << "Program terminating, Are you sure? (y/N): ";
            cin >> exitSurity;
            if (exitSurity == 'y' || exitSurity == 'Y') {
                return 0;
            }else if (exitSurity == 'n' || exitSurity == 'N') {
                system("cls");
                showin();
            }else {
                cout << "Next time choose after read the corresponding line." << endl;
                goto ExitProgram;
            }

            break;

         case 25:
             logout:
             cout << "logout, Are you sure? (y/N): ";
            cin >> exitSurity;
            if (exitSurity == 'y' || exitSurity == 'Y') {
                return 0;
            }else if (exitSurity == 'n' || exitSurity == 'N') {
                system("cls");
                showin();
            }else {
                cout << "Next time choose after read the corresponding line." << endl;
                goto logout;
            }
            break;
        default:
            cout << "Please choose between 1 - 25. Press Enter To Continue...";
            getch();
            system("cls");
            showin();
            break;
    }
}



void ShowItemList(string products)

 {
    system("cls");

    // Variables
    string choose;
    string input;
    // Variables End

    Welcome();

    string query = "select * from " + products ;
    cout << products << " products" <<endl  ;
    const char* qn = query.c_str();
    qstate = mysql_query(conn, qn );
    if (!qstate)
    {
        res = mysql_store_result(conn);
        printf("-------------------------------------------------------------------------------------------------------------\n");
        printf("| %-15s | %-15s | %-15s | %-15s | %-15s | %-15s |\n", "Name", "Company", "Arrival Date", "Expire Date", "Price", "Quantity");
        printf("-------------------------------------------------------------------------------------------------------------\n");
        while ((row = mysql_fetch_row(res)))
        {
            printf("| %-15s | %-15s | %-15s | %-15s | %-15s | %-15s |\n", row[1], row[2], row[3], row[4], row[5], row[6]);
        }
        printf("-------------------------------------------------------------------------------------------------------------\n");
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }


    ExitMenu:
    cout << "- 'm' to Menu : " << endl ;
    cout << "- 'a' to show another products : " << endl ;
    cout << "- 'l' to logout : " << endl ;
    cout << "- 'e' to exit : " << endl ;
    cin >> choose;
    if (choose == "m" || choose == "M")
    {
        menu();
    }
    if (choose == "a" || choose == "A")
    {
        showin();
    }
    if (choose == "l" || choose == "L")
    {
        main();
    }
    if (choose == "e" || choose == "E")
    {
        exit(0);
    }

    else
    {
        cout << endl << "please read the next line well\n ";
        goto ExitMenu ;
    }
}




int findin ()  // show product tables
{
    string chooseOneFromMenuString = "0" ;

    cout << "\nwhich specification you want to search in : "  << endl ;
    cout << "\nmedicine product: " << endl ;
        cout << "      1. creams" << endl;
        cout << "      2. lution" << endl;
        cout << "      3. syrup" << endl;
        cout << "      4. tablets"  << endl;
        cout << "      5. capsule" << endl;
        cout << "      6. injection" << endl;
        cout << "      7. soultion" << endl;
printf("   ---------------------\n");
    cout << "\n cosmetic: " << endl ;
        cout << "      8. Lipstick" << endl;
        cout << "      9. Primer" << endl;
        cout << "      10. Concealer" << endl;
        cout << "      11. Foundation"  << endl;
        cout << "      12. Face powder" << endl;
        cout << "      13. Rouge, blush, or blusher" << endl;
        cout << "      14. Highlight" << endl;
        cout << "      15. Bronzer" << endl;
        cout << "      16. Mascara" << endl;
        cout << "      17. Eye shadow"  << endl;
        cout << "      18. Eye liner" << endl;
 printf("   ---------------------\n");
        cout << "\n healthy product: " << endl ;
        cout << "      19. Tooth paste" << endl;
        cout << "      20. shampoo" << endl;
        cout << "      21. hair cream" << endl;
        cout << "      22. face cream"  << endl;
printf("   ---------------------\n");
        cout << "\n control: " << endl ;
        cout << "      23. main menu" << endl;
        cout << "      24. logout" << endl;
        cout << "      25. exit" << endl;


    cin >> chooseOneFromMenuString;
    int  chooseOneFromMenu;
    stringstream(chooseOneFromMenuString) >> chooseOneFromMenu ;

    char exitSurity;

   switch (chooseOneFromMenu){
        case 1:
            FindItemFromList("creams");
        break;

        case 2:
            FindItemFromList("lutions");
        break;

        case 3:
            FindItemFromList("syrup");
        break;

        case 4:
           FindItemFromList("tablets");
        break;

        case 5:
            FindItemFromList("capsule");
        break;

        case 6:
            FindItemFromList("injection");
        break;

        case 7:
            FindItemFromList("solution");
        break;

        case 8:
            FindItemFromList("Lipstick");
        break;

        case 9:
            FindItemFromList("Primer");
        break;

        case 10:
            FindItemFromList("Concealer");
        break;

        case 11:
            FindItemFromList("Foundation");
        break;

        case 12:
            FindItemFromList("Facepowder");
        break;

        case 13:
            FindItemFromList("Rouge");
        break;

        case 14:
            FindItemFromList("Highlight");
        break;

        case 15:
            FindItemFromList("Bronzer");
        break;

        case 16:
            FindItemFromList("Mascara");
        break;

        case 17:
            FindItemFromList("Eyeshadow");
        break;

        case 18:
            FindItemFromList("Eyeliner");
        break;

        case 19:
            FindItemFromList("Toothpaste");
        break;

        case 20:
            FindItemFromList("shampoo");
        break;

        case 21:
            FindItemFromList("haircream");
        break;

        case 22:
            FindItemFromList("facecream");
        break;

        case 23:
            menu();
        break;



        case 24:
            ExitProgram:
            cout << "Program terminating, Are you sure? (y/N): ";
            cin >> exitSurity;
            if (exitSurity == 'y' || exitSurity == 'Y') {
                return 0;
            }else if (exitSurity == 'n' || exitSurity == 'N') {
                system("cls");
                findin();
            }else {
                cout << "Next time choose after read the corresponding line." << endl;
                goto ExitProgram;
            }

            break;

         case 25:
             logout:
             cout << "logout, Are you sure? (y/N): ";
            cin >> exitSurity;
            if (exitSurity == 'y' || exitSurity == 'Y') {
                return 0;
            }else if (exitSurity == 'n' || exitSurity == 'N') {
                system("cls");
                findin();
            }else {
                cout << "Next time choose after read the corresponding line." << endl;
                goto logout;
            }
            break;
        default:
            cout << "Please choose between 1 - 25. Press Enter To Continue...";
            getch();
            system("cls");
            findin();
            break;
    }
}




  void FindItemFromList(string product ){
     // Initial Load
    system("cls");
    // Initial Load End

    // Variables
    string input = "";
    string choose ="";
    // Variables End

    Welcome();
    cin.ignore(1, '\n');
    cout << "Enter item Name, q to back: ";
    getline(cin, input);
    if (input == "q" ) findin ();


    string findbyname_query = "select * from " + product + " where name like '%"+input+"%'";
    const char* qn = findbyname_query.c_str();
    qstate = mysql_query(conn, qn);

    cout << endl;
    if (!qstate)
    {
        res = mysql_store_result(conn);
        if (!(row = mysql_fetch_row(res))){
                cout << "item isn't exist" << endl ;
                goto ExitMenu ;
            }

        do
        {
            printf("------------------\n") ;

            cout << "ID: " << row[0] << "\nMedicine Name: " << row[1] << "\nCompany Name: " << row[2] << "\nArrival Date: " << row[3] << "\nExpire Date: " << row[4] << "\nPrice: " << row[5] << "\nQuantity: " << row[6] << endl << endl;
        printf("------------------\n") ;
        } while ( (row = mysql_fetch_row(res)) ) ;
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    ExitMenu:
    cout << "Press 'm' to Menu,\n 'a' to Search again, \n'l' to logout, \n 'e' to Exit: ";
    cin >> choose;
    if (choose == "l" || choose == "L")
    {
        main();
    }
    if (choose == "m" || choose == "M")
    {
        menu();
    }
    else if (choose == "a" || choose == "A")
    {
        FindItemFromList(product);
    }
    else if (choose == "e" || choose == "E")
    {
        exit(0);
    }

    else
    {
        cout << endl << "please choose a valid answer " << endl ;
        goto ExitMenu ;
    }
}




int addin() {

    string chooseOneFromMenuString = "0" ;

    cout << "\nwhich specification you want to add products in: "  << endl ;
    cout << "\nmedicine product: " << endl ;
        cout << "      1. creams" << endl;
        cout << "      2. lutions" << endl;
        cout << "      3. syrup" << endl;
        cout << "      4. tablets"  << endl;
        cout << "      5. capsule" << endl;
        cout << "      6. injection" << endl;
        cout << "      7. solution" << endl;
printf("   ---------------------\n");
    cout << "\n cosmetic: " << endl ;
        cout << "      8. Lipstick" << endl;
        cout << "      9. Primer" << endl;
        cout << "      10. Concealer" << endl;
        cout << "      11. Foundation"  << endl;
        cout << "      12. Face powder" << endl;
        cout << "      13. Rouge, blush, or blusher" << endl;
        cout << "      14. Highlight" << endl;
        cout << "      15. Bronzer" << endl;
        cout << "      16. Mascara" << endl;
        cout << "      17. Eye shadow"  << endl;
        cout << "      18. Eye liner" << endl;
 printf("   ---------------------\n");
        cout << "\n healthy product: " << endl ;
        cout << "      19. Tooth paste" << endl;
        cout << "      20. shampoo" << endl;
        cout << "      21. hair cream" << endl;
        cout << "      22. face cream"  << endl;
printf("   ---------------------\n");
        cout << "\n control: " << endl ;
        cout << "      23. main menu" << endl;
        cout << "      24. logout" << endl;
        cout << "      25. exit" << endl;


    cin >> chooseOneFromMenuString;
    int  chooseOneFromMenu;
    stringstream(chooseOneFromMenuString) >> chooseOneFromMenu ;
    char exitSurity;
   switch (chooseOneFromMenu){
        case 1:
            AddIteminStock("creams");
        break;

        case 2:
            AddIteminStock("lutions");
        break;

        case 3:
            AddIteminStock("syrup");
        break;

        case 4:
           AddIteminStock("tablets");
        break;

        case 5:
            AddIteminStock("capsule");
        break;

        case 6:
            AddIteminStock("injection");
        break;

        case 7:
            AddIteminStock("solution");
        break;

        case 8:
            AddIteminStock("Lipstick");
        break;

        case 9:
            AddIteminStock("Primer");
        break;

        case 10:
            AddIteminStock("Concealer");
        break;

        case 11:
            AddIteminStock("Foundation");
        break;

        case 12:
            AddIteminStock("Facepowder");
        break;

        case 13:
            AddIteminStock("Rouge");
        break;

        case 14:
            AddIteminStock("Highlight");
        break;

        case 15:
            AddIteminStock("Bronzer");
        break;

        case 16:
            AddIteminStock("Mascara");
        break;

        case 17:
            AddIteminStock("Eyeshadow");
        break;

        case 18:
            AddIteminStock("Eyeliner");
        break;

        case 19:
            AddIteminStock("Toothpaste");
        break;

        case 20:
            AddIteminStock("shampoo");
        break;

        case 21:
            AddIteminStock("haircream");
        break;

        case 22:
            AddIteminStock("facecream");
        break;

        case 23:
            menu();
        break;
        case 24:
            ExitProgram:
            cout << "Program terminating, Are you sure? (y/N): ";
            cin >> exitSurity;
            if (exitSurity == 'y' || exitSurity == 'Y') {
                return 0;
            }else if (exitSurity == 'n' || exitSurity == 'N') {
                system("cls");
                addin();
            }else {
                cout << "Next time choose after read the corresponding line." << endl;
                goto ExitProgram;
            }

            break;

         case 25:
             logout:
             cout << "logout, Are you sure? (y/N): ";
            cin >> exitSurity;
            if (exitSurity == 'y' || exitSurity == 'Y') {
                return 0;
            }else if (exitSurity == 'n' || exitSurity == 'N') {
                system("cls");
                addin();
            }else {
                cout << "Next time choose after read the corresponding line." << endl;
                goto logout;
            }
            break;
        default:
            cout << "Please choose between 1 - 25. Press Enter To Continue...";
            getch();
            system("cls");
            addin();
            break;
    }
}




void AddIteminStock(string product ){
// Initial Load
    system("cls");
    // Initial Load End

    // Variables
    string id = "";
    string name = "";
    string company = "";
    string arrival_date = "";
    string expire_date = "";
    string price = "";
    string quantity = "";
    char choose;
    // Variables End

    Welcome();
    cout << "   - add in " << product << " table" << endl << endl ;
    cin.ignore(1, '\n');
    cout << "Enter id, q to back: ";
    getline(cin, id);
    if (id == "q") addin()  ;
    cout << "Enter Name, q to back: ";
    getline(cin, name);
    if (name == "q") addin()  ;
    cout << "Enter Company, q to back: ";
    getline(cin, company);
    if (company == "q") addin()  ;
    cout << "Enter Arrival Date (dd-mm-yyyy), q to back: ";
    getline(cin, arrival_date);
    if (arrival_date == "q") addin()  ;
    cout << "Enter Expire Date (dd-mm-yyyy), q to back: ";
    getline(cin, expire_date);
    if (expire_date == "q") addin()  ;
    cout << "Enter Price, q to back: ";
    getline(cin, price);
    if (price == "q") addin()  ;
    cout << "Enter Quantity, q to back: ";
    getline(cin, quantity);
    if (quantity == "q") addin()  ;

    string insert_query = "insert into " + product + " values ( '"+id+"', '"+name+"','"+company+"','"+arrival_date+"','"+expire_date+"','"+price+"','"+quantity+"')";
    const char* q = insert_query.c_str(); // c_str converts string to constant char and this is required
    qstate = mysql_query(conn, q);
    if (!qstate)
    {
        cout << endl << "Successfully added in database." << endl;
    }

    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    // Exit Code
    cout << "Press 'm' to Menu and 'a' to Insert Again Or Any Other key to exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        menu();
    }
    else if (choose == 'a' || choose == 'A')
    {
        AddIteminStock(product);
    }
    else
    {
        exit(0);
    }
}






int updatein() {

    string chooseOneFromMenuString = "0" ;

    cout << "\nwhich specification you want to update products in: "  << endl ;
    cout << "\nmedicine product: " << endl ;
        cout << "      1. creams" << endl;
        cout << "      2. lutions" << endl;
        cout << "      3. syrup" << endl;
        cout << "      4. tablets"  << endl;
        cout << "      5. capsule" << endl;
        cout << "      6. injection" << endl;
        cout << "      7. solution" << endl;
printf("   ---------------------\n");
    cout << "\n cosmetic: " << endl ;
        cout << "      8. Lipstick" << endl;
        cout << "      9. Primer" << endl;
        cout << "      10. Concealer" << endl;
        cout << "      11. Foundation"  << endl;
        cout << "      12. Face powder" << endl;
        cout << "      13. Rouge, blush, or blusher" << endl;
        cout << "      14. Highlight" << endl;
        cout << "      15. Bronzer" << endl;
        cout << "      16. Mascara" << endl;
        cout << "      17. Eye shadow"  << endl;
        cout << "      18. Eye liner" << endl;
 printf("   ---------------------\n");
        cout << "\n healthy product: " << endl ;
        cout << "      19. Tooth paste" << endl;
        cout << "      20. shampoo" << endl;
        cout << "      21. hair cream" << endl;
        cout << "      22. face cream"  << endl;
printf("   ---------------------\n");
        cout << "\n control: " << endl ;
        cout << "      23. main menu" << endl;
        cout << "      24. logout" << endl;
        cout << "      25. exit" << endl;


    cin >> chooseOneFromMenuString;
    int  chooseOneFromMenu;
    stringstream(chooseOneFromMenuString) >> chooseOneFromMenu ;
    char exitSurity;
   switch (chooseOneFromMenu){
        case 1:
            UpdateStockItem("creams");
        break;

        case 2:
            UpdateStockItem("lutions");
        break;

        case 3:
            UpdateStockItem("syrup");
        break;

        case 4:
           UpdateStockItem("tablets");
        break;

        case 5:
            UpdateStockItem("capsule");
        break;

        case 6:
            UpdateStockItem("injection");
        break;

        case 7:
            UpdateStockItem("solution");
        break;

        case 8:
            UpdateStockItem("Lipstick");
        break;

        case 9:
            UpdateStockItem("Primer");
        break;

        case 10:
            UpdateStockItem("Concealer");
        break;

        case 11:
            UpdateStockItem("Foundation");
        break;

        case 12:
            UpdateStockItem("Facepowder");
        break;

        case 13:
            UpdateStockItem("Rouge");
        break;

        case 14:
            UpdateStockItem("Highlight");
        break;

        case 15:
            UpdateStockItem("Bronzer");
        break;

        case 16:
            UpdateStockItem("Mascara");
        break;

        case 17:
            UpdateStockItem("Eyeshadow");
        break;

        case 18:
            UpdateStockItem("Eyeliner");
        break;

        case 19:
            UpdateStockItem("Toothpaste");
        break;

        case 20:
            UpdateStockItem("shampoo");
        break;

        case 21:
            UpdateStockItem("haircream");
        break;

        case 22:
            UpdateStockItem("facecream");
        break;

        case 23:
            menu();
        break;
        case 24:
            ExitProgram:
            cout << "Program terminating, Are you sure? (y/N): ";
            cin >> exitSurity;
            if (exitSurity == 'y' || exitSurity == 'Y') {
                return 0;
            }else if (exitSurity == 'n' || exitSurity == 'N') {
                system("cls");
                updatein();
            }else {
                cout << "Next time choose after read the corresponding line." << endl;
                goto ExitProgram;
            }

            break;

         case 25:
             logout:
             cout << "logout, Are you sure? (y/N): ";
            cin >> exitSurity;
            if (exitSurity == 'y' || exitSurity == 'Y') {
                return 0;
            }else if (exitSurity == 'n' || exitSurity == 'N') {
                system("cls");
                updatein();
            }else {
                cout << "Next time choose after read the corresponding line." << endl;
                goto logout;
            }
            break;
        default:
            cout << "Please choose between 1 - 25. Press Enter To Continue...";
            getch();
            system("cls");
            updatein();
            break;
    }
}



void UpdateStockItem(string product) {
system("cls");

    // Variables
    string name = "";
    string company = "";
    string arrival_date = "";
    string expire_date = "";
    string price = "";
    string quantity = "";
    string items[5000];
    string choose;

    bool HaveException = false;
    bool NotInDatabase = true;
    int indexForId = 0;

    // Store Variables
    string itemId="";
    string storeid = "";
    string storename = "";
    string storecompany = "";
    string storearrival_date = "";
    string storeexpire_date = "";
    string storeprice = "";
    string storequantity = "";
    // Variables End

    Welcome();
    string update_query = "select * from " + product ;
    cout << product << " product" ;
    cout << " \n" ;
    const char* qn = update_query.c_str();
    qstate = mysql_query(conn, qn );
    if (!qstate)
    {
        res = mysql_store_result(conn);
        printf("---------------------------------------------------------------------------------------------------------\n");
        printf("| %-10s | %-15s | %-15s | %-15s | %-15s | %-5s | %-8s |\n", "Column Id", "Name", "Company", "Arrival Date", "Expire Date", "Price", "Quantity");
        printf("---------------------------------------------------------------------------------------------------------\n");
        while ((row = mysql_fetch_row(res)))
        {

                printf("| %-10s | %-15s | %-15s | %-15s | %-15s | %-5s | %-8s |\n", row[0], row[1], row[2], row[3], row[4], row[5], row[6]);

                items[indexForId] = row [0] ;
                indexForId++ ;


       }
        printf("---------------------------------------------------------------------------------------------------------\n");

    }



    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }


    try
    {
        cout << endl;
        cout << "Enter Item ID: ";
        cin >> itemId;
        cout << endl;
    }

    catch (exception e)
    {
        cout << "Please Enter a valid NUMBER." << endl;
        HaveException = true;
        goto ExitMenu;
    }


    if (HaveException == false)
    {

        for (int i = 0; i < indexForId; i++)
        {

            if ( itemId != items[i])
            {
                NotInDatabase = true;
            }
            else
            {
                NotInDatabase = false;
                break;
            }
        }


        if (NotInDatabase == false)
 {

            string findbyid_query = "select * from " + product + " where id = '"+itemId+"'";
            const char* qi = findbyid_query.c_str();
            qstate = mysql_query(conn, qi);

            if (!qstate)
            {
                res = mysql_store_result(conn);
                while (row = mysql_fetch_row(res))
                {
                    cout << "Column ID: " << row[0]
                         << "\nName: " << row[1]
                         << "\nCompany: " << row[2]
                         << "\nArrival Date: " << row[3]
                         << "\nExpire Date: " << row[4]
                         << "\nPrice: " << row[5]
                         << "\nQuantity: " << row[6]
                         << endl << endl;

                    storeid = row[0];
                    storename = row[1];
                    storecompany = row[2];
                    storearrival_date = row[3];
                    storeexpire_date = row[4];
                    storeprice = row[5];
                    storequantity = row[6];

                }
            }else
            {
                cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
            }



            cin.ignore(1, '\n');
            string defaultString = "x";
            cout << "Enter Name, q to back, (" << defaultString << "  to not change): ";
            getline(cin, name);

            if (name == defaultString)
            {
                name = storename;
            }
            if (name == "q")
            {
                 updatein() ;
            }
            cout << "Enter Company, q to back, (" << defaultString << "  to not change): ";
            getline(cin, company);

            if (company == defaultString)
            {
                company = storecompany;
            }
            if (company == "q")
            {
                 updatein() ;
            }

            cout << "Enter Arrival Date, q to back, (" << defaultString << "  to not change) (yyyy-mm-dd): ";
            getline(cin, arrival_date);
            if (arrival_date == defaultString)
            {
                arrival_date = storearrival_date;
            }
            if (arrival_date == "q")
            {
                 updatein() ;
            }

            cout << "Enter Expire Date, q to back, (" << defaultString << "  to not change) (yyyy-mm-dd): ";
            getline(cin, expire_date);
            if (expire_date == defaultString)
            {
                expire_date = storeexpire_date;
            }
            if (expire_date == "q")
            {
                 updatein() ;
            }

            cout << "Enter Price, q to back, (" << defaultString << "  to not change): ";
            getline(cin, price);
            if (price == defaultString)
            {
                price = storeprice;
            }
            if (price == "q")
            {
                 updatein() ;
            }

            cout << "Enter Quantity, q to back, (" << defaultString << "  to not change): ";
            cin >> quantity;
            if (quantity == defaultString)
            {
                 quantity = storequantity;
            }
            if (quantity == "q")
            {
                 updatein() ;
            }




            string update_query = "update " + product + " set name = '"+name+"', company = '"+company+"', arrival_date = '"+arrival_date+"', expiration_date = '"+expire_date+"', price = '"+price+"', quantity = '"+quantity+"' where id = '"+storeid +"'";
            const char* qu = update_query.c_str();
            qstate = mysql_query(conn, qu);
            if (!qstate)
            {
                cout << endl << "Successfully Updated." << endl;
            }
            else
            {
                cout << "Failed To Update!" << mysql_errno(conn) << endl;
            }

    }



        out:
            if ( NotInDatabase == true){
            cout << "Item Not Found in database." << endl;
            }


    ExitMenu:
    cout << "Press 'm' to Menu, 'a' to update another item and any 'e' to Exit: ";
    cin >> choose;
    if (choose == "m" || choose == "M")
    {
        main();
    }
    else if (choose == "a" || choose == "A")
    {
        UpdateStockItem(product);
    }
    else if (choose == "e" || choose == "E")
    {
        exit(0);
    }


    else
    {
        cout << "please read the next line well\n" ;
        goto ExitMenu;
    }
}
}



int deletein() {
     string chooseOneFromMenuString = "0" ;

    cout << "\nwhich specification you want to delete its products : "  << endl ;
    cout << "\nmedicine product: " << endl ;
        cout << "      1. creams" << endl;
        cout << "      2. lutions" << endl;
        cout << "      3. syrup" << endl;
        cout << "      4. tablets"  << endl;
        cout << "      5. capsule" << endl;
        cout << "      6. injection" << endl;
        cout << "      7. solution" << endl;
printf("   ---------------------\n");
    cout << "\n cosmetic: " << endl ;
        cout << "      8. Lipstick" << endl;
        cout << "      9. Primer" << endl;
        cout << "      10. Concealer" << endl;
        cout << "      11. Foundation"  << endl;
        cout << "      12. Face powder" << endl;
        cout << "      13. Rouge, blush, or blusher" << endl;
        cout << "      14. Highlight" << endl;
        cout << "      15. Bronzer" << endl;
        cout << "      16. Mascara" << endl;
        cout << "      17. Eye shadow"  << endl;
        cout << "      18. Eye liner" << endl;
 printf("   ---------------------\n");
        cout << "\n healthy product: " << endl ;
        cout << "      19. Tooth paste" << endl;
        cout << "      20. shampoo" << endl;
        cout << "      21. hair cream" << endl;
        cout << "      22. face cream"  << endl;
printf("   ---------------------\n");
        cout << "\n control: " << endl ;
        cout << "      23. main menu" << endl;
        cout << "      24. logout" << endl;
        cout << "      25. exit" << endl;


    cin >> chooseOneFromMenuString;


    int  chooseOneFromMenu;
    stringstream(chooseOneFromMenuString) >> chooseOneFromMenu ;

    char exitSurity;
   switch (chooseOneFromMenu){
        case '1':
            DeleteStockItem ("creams");
        break;

        case 2:
            DeleteStockItem ("lutions");
        break;

        case 3:
            DeleteStockItem ("syrup");
        break;

        case 4:
           DeleteStockItem ("tablets");
        break;

        case 5:
            DeleteStockItem ("capsule");
        break;

        case 6:
            DeleteStockItem ("injection");
        break;

        case 7:
            DeleteStockItem ("solution");
        break;

        case 8:
            DeleteStockItem ("Lipstick");
        break;

        case 9:
            DeleteStockItem ("Primer");
        break;

        case 10:
            DeleteStockItem ("Concealer");
        break;

        case 11:
            DeleteStockItem ("Foundation");
        break;

        case 12:
            DeleteStockItem ("Facepowder");
        break;

        case 13:
            DeleteStockItem ("Rouge");
        break;

        case 14:
            DeleteStockItem ("Highlight");
        break;

        case 15:
            DeleteStockItem ("Bronzer");
        break;

        case 16:
            DeleteStockItem ("Mascara");
        break;

        case 17:
            DeleteStockItem ("Eyeshadow");
        break;

        case 18:
            DeleteStockItem ("Eyeliner");
        break;

        case 19:
            DeleteStockItem ("Toothpaste");
        break;

        case 20:
            DeleteStockItem ("shampoo");
        break;

        case 21:
            DeleteStockItem ("haircream");
        break;

        case 22:
            DeleteStockItem ("facecream");
        break;

        case 23:
            menu();
        break;
        case 24:
            ExitProgram:
            cout << "Program terminating, Are you sure? (y/N): ";
            cin >> exitSurity;
            if (exitSurity == 'y' || exitSurity == 'Y') {
                return 0;
            }else if (exitSurity == 'n' || exitSurity == 'N') {
                system("cls");
                deletein();
            }else {
                cout << "Next time choose after read the corresponding line." << endl;
                goto ExitProgram;
            }

            break;

         case 25:
             logout:
             cout << "logout, Are you sure? (y/N): ";
            cin >> exitSurity;
            if (exitSurity == 'y' || exitSurity == 'Y') {
                return 0;
            }else if (exitSurity == 'n' || exitSurity == 'N') {
                system("cls");
                deletein();
            }else {
                cout << "Next time choose after read the corresponding line." << endl;
                goto logout;
            }
            break;
        default:
            cout << "Please choose between 1 - 25. Press Enter To Continue...";
            getch();
            system("cls");
            deletein();
            break;
    }
}


void DeleteStockItem ( string product ) {
    system("cls");

    // Variables
    char choose;
    string itemId;
    string items[5000];
    int indexForId = 0;
    bool HaveException = false, NotInDatabase = false;
    // Variables End


    Welcome();

        cout << product << " products" << endl ;
      string delete_query = "select * from " + product ;
    const char* qn = delete_query.c_str();
    string query ;
    cout << query ;
    qstate = mysql_query(conn, qn);

    if (!qstate)
    {
        res = mysql_store_result(conn);
        printf("----------------------------------------------------------\n");
        printf("| %-10s | %-15s | %-10s | %-10s |\n", "Column Id", "Name", "Price", "Quantity");
        printf("----------------------------------------------------------\n");
        while ((row = mysql_fetch_row(res)))
        {
            printf("| %-10s | %-15s | %-10s | %-10s |\n", row[0], row[1], row[5], row[6]);
            items[indexForId] = row[0];
            indexForId++;
        }
        printf("----------------------------------------------------------\n");
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }


    try
    {
        cout << endl;
        cout << "Enter Item ID , q to back: ";
        cin >> itemId;
        cout << endl;
        if ( (itemId == "q") || (itemId == "Q")) { deletein(); }
    }
    catch (exception e)
    {
        cout << "Please Enter a valid NUMBER." << endl;

        HaveException = true;
        goto ExitMenu;
    }

    if (HaveException == false)
    {

        for (int i = 0; i < indexForId; i++)
        {
            if (itemId != items[i])
            {
                NotInDatabase = true;
            }else
            {
                NotInDatabase = false;
                break;
            }
        }

        if (NotInDatabase == false)
        {
            string delete_query = "delete from " +product+ " where id = '"+itemId+"'";
            const char* qd = delete_query.c_str();
            qstate = mysql_query(conn, qd);

            if (!qstate)
            {
                cout << "Successfully Deleted." << endl;
            }
            else
            {
                cout << "Failed To Delete!" << mysql_errno(conn) << endl;
            }

        }
        else
        {
            cout << "Item Not Found in database." << endl;
        }
    }



    // Exit Code
    ExitMenu:
    cout<< "Press 'm' to Menu, 'd' to delete another item, 'e' Exit: ";

    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        menu();
    }
    else if (choose == 'd' || choose == 'D')
    {
        DeleteStockItem(product);
    }
    else if (choose == 'e' || choose == 'E')
    {
        exit(0);
    }

    else
    {
        cout << "\nyou entered a wrong choose, please read the next line well\n " ;
        goto ExitMenu;
    }
}
