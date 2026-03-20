#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Customer Details Structure */
typedef struct customer
{
    char name[100];
    char address[500];
    unsigned long long int Aadhaar_id;
    char pan_id[16];
    unsigned long long int mob_no;
	//char dob[];
	short int age;
} customer;

/* Nominee Details Structure */
typedef struct nominee
{
    customer cust;
    char relation[20];
} nominee;

/* Banking Details Structure */
typedef struct Banking
{
    unsigned long long int sav_ac_no;
    unsigned long long int cur_ac_no;
    char IFSC_code[20];
    long int balance;
}Banking;

/*Global veriable*/
unsigned long long int MIN_SAVINGS_ACC = 1200010100100;
unsigned long long int MAX_SAVINGS_ACC = 1200010100599;

unsigned long long int MIN_CURRENT_ACC = 1200010100600;
unsigned long long int MAX_CURRENT_ACC = 1200010101200;
char IFSC_code[20]= "BANDW0000001";                    

/* Main Structure*/
typedef struct accountdetails
{
    // int choice;
    customer cust;
    nominee nom;
    Banking bank;
    struct accountdetails *next;
} accountdetails;

/* Global pointer */
accountdetails *new,*temp,*head=NULL,*dest,*previous=NULL;

/*Function declaration*/
    void Bank();
    void CreateAccount();
    void printPassbook();
    void balanceTransfer();
    void viewAndUpdateAccountHolder();
    void WithdrawalBalance();
    void DepositeBalance();
    void updateBankDetails(accountdetails *new);
    void Loan();
    void displayAllaccount(accountdetails *head);
    void deleteAccount();
    void BalanceEnquiry();
    void Save();
    void Load();

int main()
{
    int user_type;
    TAKEINPUT:
    printf("--------------------------* Welcome to BLACK AND WHITE bank pvt ltd *--------------------------\n");
    
    while(1)
    {
BANK_OP:
    printf("1.  Branch Manager\n2.  Frontline Staff\n3.  Exit\n");
    printf("Enter User type :");
    scanf("%d",&user_type);
    if((user_type>=1) && (user_type<=2))
    {
    while(user_type==2)
    {    
        int choice,op=1;
    while(op)
        {
        printf("--------------------------* Welcome to BLACK AND WHITE Bank pvt ltd *--------------------------\n");
        printf("--------------------------------------------- Menu ---------------------------------------------\n");
        printf("1. Create account\n2. printPassbook\n3. Balance Enquiry\n4. WithdrawalBalance\n5. Deposite Balance"
            "\n6. Balance Transfer\n7. Delete Account\n8. View & Update Account Holder Details\n9. Loan\n10. Exit\n");
        printf("----------------------------------------------------------------------------------------------\n");
        printf("Select your choice from the menu: ");
        scanf("%d",&choice);
        switch(choice)
            {
                case 1:
                    /*Calling CreateAccount() Function line no 127*/
                    CreateAccount();
                    printf("-------------------------------------------Account created-------------------------------------------\n");
                    break;

                case 2:
                    printPassbook(temp);
                    break;
                    
                case 3:
                    printf("Search and Update account holder details\n");
                    BalanceEnquiry();
                    break;

                case 4:
                    /*Calling WithdrawalBalance() Function line no 282*/
                    WithdrawalBalance(head);
                    break;

                case 5:
                    /*Calling DepositeBalance() Function line no 348*/
                    DepositeBalance(head);
                    break;

                case 6:
                    /*Calling DepositeBalance() Function line no 348*/
                    balanceTransfer();
                    break;

                case 7:
                    deleteAccount();
                    break;

                case 8:
                    viewAndUpdateAccountHolder(head);
                    Loan();
                    break;

                case 9:
                    Loan();
                    break;
                
                case 10:
                    goto BANK_OP;
                    //break;
                default:
                    break;

            } //switch block end
            printf("Enter the operation 1 to continue 0 to exit: ");
            scanf("%d",&op);

        } //    while(op) end
        break;
    } //    while(user_type==2) block end
    while(user_type==1)
    {
        int choose;
        printf("--------------------------* Welcome to BLACK AND WHITE Bank pvt ltd *--------------------------\n");
        printf("--------------------------------------------- Menu ---------------------------------------------\n");
        printf("1. Display all Account\n2. Load\n3. Exit\n");
        printf("----------------------------------------------------------------------------------------------\n");
        printf("Choose from the menu: ");
        scanf("%d",&choose);
        switch(choose)
        {
            case 1:
                displayAllaccount(head);
                break;

            case 2:
                Load();
            
            case 3:
                break;

            default:
                break;
        }
        break;
    }
    } //    if((user_type>=1) && (user_type<=2)) block end
    else
    {
        if (user_type==3)
        {
            break;
        }
        else
        {
            printf("\nInvalid Input..!!!  Please enter a valid input\n");
        goto TAKEINPUT;
        }
        
    }
    }
}   //main() block end

void CreateAccount()
{
    //Load();
    printf("\n---------------------------------------Account Holder details---------------------------------------\n");
    new=(accountdetails *)malloc(sizeof(accountdetails));
    printf("Account Holder Name : ");
    scanf(" %[^\n]s",new->cust.name);

    // printf("Account Holder Address : ");
    // scanf(" %[^\n]s",new->cust.address);

    // printf("Account Holder Aadhaar_id : ");
    // scanf("%d",&new->cust.Aadhaar_id);

    // printf("Account Holder pan_id : ");
    // scanf(" %[^\n]s",new->cust.pan_id);

    // printf("Account Holder mob_no : ");
    // scanf("%llu",&new->cust.mob_no);

    // printf("Account Holder age : ");
    // scanf("%hd",&new->cust.age);
    // printf("\n---------------------------------------Account Holder Nominee details---------------------------------------\n");
    
    // printf("Account Holder Nominee Name : ");
    // scanf(" %[^\n]s",new->nom.cust.name);

    // printf("Account Holder Nominee Address : ");
    // scanf(" %[^\n]s",new->nom.cust.address);

    // printf("Account Holder Nominee Aadhaar_id : ");
    // scanf("%llu",new->nom.cust.Aadhaar_id);

    // printf("Account Holder Nominee pan_id : ");
    // scanf(" %[^\n]s",new->nom.cust.pan_id);

    // printf("Account Holder Nominee mob_no : ");
    // scanf("%llu",new->nom.cust.mob_no);

    // printf("Account Holder Nominee mob_no : ");
    // scanf("%hd",new->nom.cust.age);

    // printf("Relation with Account Holder : ");
    // scanf(" %[^\n]s",new->nom.relation);
    
    Bank(new);
    Save();
    new->next=NULL;

    if(head==NULL)
    {
        head=temp=new;
    }
    else
    {
        temp->next=new;
        temp=new;
    }
    
    //temp=head;
}

void Bank(accountdetails *acc)
{
    int ac_type;
    static unsigned long long int savings_acc_count = 0;
    static unsigned long long int curr_acc_count = 0;
    new->bank.sav_ac_no = 0;    //1200010100100;
    new->bank.cur_ac_no = 0;    //1200010100600;
    strcpy(new->bank.IFSC_code, "BANDW0000001");
    printf("Chose Account Type (1. Savings 2. Current) : ");
    scanf("%d",&ac_type);
MIN_AMT:    
    printf("Enter deposit_amount Savings( LIMIT RS ( 0 > 2,00,000 ) ) / Current( LIMIT RS ( 2,00,000 > 10,00,00,000 ) ): ");
    scanf(" %ld",&(new->bank.balance));
    switch(ac_type)
        {
            case 1 :
                    
                    if( new->bank.balance > 0 && new->bank.balance < 200000 )
                    {
                        printf("\nSavings account created...\nYour first deposited amount is= %d\n",new->bank.balance);
                        new->bank.sav_ac_no = MIN_SAVINGS_ACC + savings_acc_count;
                        savings_acc_count++;                 
                    }
                    else
                    {
                        printf("\nYour deposited amount is Exceeded ( LIMIT RS ( 0 > 2,00,000 ) )\n");
                        goto MIN_AMT;
                    }
                    break;
                    
            case 2 :
                    if(new->bank.balance > 200000 && new->bank.balance < 100000000 )
                    {
                        printf("\nCurrent account created...\nYour first deposited amount is= %d\n",new->bank.balance);
                        new->bank.cur_ac_no = MIN_CURRENT_ACC + curr_acc_count;
                        curr_acc_count++;
                    }
                    else
                    {
                        printf("\nYour deposited amount is Exceeded ( LIMIT RS ( 2,00,000 > 10,00,00,000 ) )\n");
                        goto MIN_AMT;
                    }
                    break;
                    
        }
}
void viewAndUpdateAccountHolder()
{
    printf("***************************************Account Holder Details*********************************\n");
    temp=head;
    unsigned long long int acount_number;
    printf("Enter the Acount Number of the customer : ");
    scanf("%llu", &acount_number);
    while(temp!=NULL)
{
    if((acount_number>=MIN_SAVINGS_ACC)&&(acount_number<=MAX_SAVINGS_ACC))
    {
        if(temp->bank.sav_ac_no==acount_number)
        {
            printPassbook(temp);
            int updateAcDetails;
            printf("Do you want to Update ( 1. YES / 2. NO ): ");
            scanf("%d",&updateAcDetails);
                if(updateAcDetails==1)
                {
                    updateBankDetails(temp);
                    break;
                }
            
        }

    }
    else if((acount_number>=MIN_CURRENT_ACC)&&(acount_number<=MAX_CURRENT_ACC))
    {
            if(temp->bank.cur_ac_no==acount_number)
        {
            printPassbook(temp);
            int updateAcDetails;
            printf("Do you want to Update ( 1. YES / 2. NO ): ");
            scanf("%d",&updateAcDetails);
                if(updateAcDetails==1)
                {
                    updateBankDetails(temp);
                }
                else
                {
                    break;
                }
        }
    }
    else if(temp==NULL)
    {
        printf("Bank account number not found.\n");
        return;
    }
    temp=temp->next;
    
    
}

} 
void printPassbook()
{
    // while(temp!=NULL)
    // {
    
    printf("\n---------------------------------------Account Holder details---------------------------------------\n");
    printf("Account Holder Name : %s\n",temp->cust.name);
    printf("Account Holder Address : %s\n",temp->cust.address);
    printf("Account Holder Aadhaar_id : %llu\n",temp->cust.Aadhaar_id);
    printf("Account Holder Pan_id : %s\n",temp->cust.pan_id);
    printf("Account Holder Mob_no : %llu\n",temp->cust.mob_no);
    printf("Account Holder Age : %d\n",temp->cust.age);
    // printf("\n---------------------------------------Account Holder Nominee details---------------------------------------\n");

    // printf("Account Holder Nominee Name : %s\n",new->cust.name);
    // printf("Account Holder Nominee Address : %s\n",new->cust.address);
    // printf("Account Holder Nominee Aadhaar_id : %llu\n",new->cust.Aadhaar_id);
    // printf("Account Holder Nominee Pan_id : %s\n",new->cust.pan_id);
    // printf("Account Holder Nominee Mob_no : %llu\n",new->cust.mob_no);
    // printf("Account Holder Nominee Age : %d\n",new->cust.age);

    if((temp->bank.sav_ac_no>=MIN_SAVINGS_ACC)&&(temp->bank.sav_ac_no<MAX_SAVINGS_ACC))
    {
        printf("Account Holder Savings Bank account no : %llu\n",temp->bank.sav_ac_no);
        printf("Account Holder IFSC_code : %s\n",temp->bank.IFSC_code);
        printf("Account Holder Bank Balance : %d\n",temp->bank.balance);
    }
    else if((temp->bank.cur_ac_no>=MIN_CURRENT_ACC)&&(temp->bank.cur_ac_no<MAX_CURRENT_ACC))
    {
        printf("Account Holder Current Bank account no : %llu\n",temp->bank.cur_ac_no);
        printf("Account Holder IFSC_code : %s\n",temp->bank.IFSC_code);
        printf("Account Holder Bank Balance : %d\n",temp->bank.balance);
    }
}

void updateBankDetails(accountdetails *temp)
{
    unsigned long long int acount_number;
    printf("---------------------------------------Updation In Progress---------------------------------------\n");
    // while((temp != NULL) != acount_number)
    // {
    //     temp=temp->next;
    // }
    // if(temp==NULL)
    // {
    //     printf("Bank account number not found.\n");
    //     return;
    // }
    printf("Account Holder Name : ");
    scanf(" %[^\n]s",temp->cust.name);

    // printf("Account Holder Address : ");
    // scanf(" %[^\n]s",new->cust.address);

    // printf("Account Holder Aadhaar_id : ");
    // scanf("%d",&new->cust.Aadhaar_id);

    // printf("Account Holder pan_id : ");
    // scanf(" %[^\n]s",new->cust.pan_id);

    // printf("Account Holder mob_no : ");
    // scanf("%llu",&new->cust.mob_no);

    // printf("Account Holder age : ");
    // scanf("%hd",&new->cust.age);
    // printf("\n---------------------------------------Account Holder Nominee details---------------------------------------\n");
    
    // printf("Account Holder Nominee Name : ");
    // scanf(" %[^\n]s",new->nom.cust.name);

    // printf("Account Holder Nominee Address : ");
    // scanf(" %[^\n]s",new->nom.cust.address);

    // printf("Account Holder Nominee Aadhaar_id : ");
    // scanf("%llu",new->nom.cust.Aadhaar_id);

    // printf("Account Holder Nominee pan_id : ");
    // scanf(" %[^\n]s",new->nom.cust.pan_id);

    // printf("Account Holder Nominee mob_no : ");
    // scanf("%llu",new->nom.cust.mob_no);

    // printf("Account Holder Nominee mob_no : ");
    // scanf("%hd",new->nom.cust.age);

    // printf("Relation with Account Holder : ");
    // scanf(" %[^\n]s",new->nom.relation);
    printf("**************************************Successfully Updated**************************************\n");
}



void displayAllaccount(accountdetails *head)
{
    accountdetails *temp=head;
    int count = 1;
    while(temp!=NULL)
    {
    
    printf("\n---------------------------------------Account Holder details---------------------------------------\n");

    printf("Customer No : %d\n",count);
    printf("Account Holder Name : %s\n",temp->cust.name);
    printf("Account Holder Address : %s\n",temp->cust.address);
    printf("Account Holder Aadhaar_id : %llu\n",temp->cust.Aadhaar_id);
    printf("Account Holder Pan_id : %s\n",temp->cust.pan_id);
    printf("Account Holder Mob_no : %llu\n",temp->cust.mob_no);
    printf("Account Holder Age : %d\n",temp->cust.age);
    // printf("\n---------------------------------------Account Holder Nominee details---------------------------------------\n");

    // printf("Account Holder Nominee Name : %s\n",new->cust.name);
    // printf("Account Holder Nominee Address : %s\n",new->cust.address);
    // printf("Account Holder Nominee Aadhaar_id : %llu\n",new->cust.Aadhaar_id);
    // printf("Account Holder Nominee Pan_id : %s\n",new->cust.pan_id);
    // printf("Account Holder Nominee Mob_no : %llu\n",new->cust.mob_no);
    // printf("Account Holder Nominee Age : %d\n",new->cust.age);

    if((temp->bank.sav_ac_no>=MIN_SAVINGS_ACC)&&(temp->bank.sav_ac_no<MAX_SAVINGS_ACC))
    {
        printf("Account Holder Savings Bank account no : %llu\n",temp->bank.sav_ac_no);
        printf("Account Holder IFSC_code : %s\n",temp->bank.IFSC_code);
        printf("Account Holder Bank Balance : %d\n",temp->bank.balance);
    }
    else if((temp->bank.cur_ac_no>=MIN_CURRENT_ACC)&&(temp->bank.cur_ac_no<MAX_CURRENT_ACC))
    {
        printf("Account Holder Current Bank account no : %llu\n",temp->bank.cur_ac_no);
        printf("Account Holder IFSC_code : %s\n",temp->bank.IFSC_code);
        printf("Account Holder Bank Balance : %d\n",temp->bank.balance);
    }
    count++;    
    temp=temp->next;
    }
}

void WithdrawalBalance() 
{
    printf("\n------------------------------------------Withdrawal Balance------------------------------------------\n");
    unsigned long long int Bank_account_no=0;
    temp=head;
    printf("Enter the Bank account no: ");
    scanf("%llu", &Bank_account_no);
    int flag=0;

        while(temp!=NULL)
        {
            long int amount=0;
            if((Bank_account_no>=MIN_SAVINGS_ACC)&&(Bank_account_no<=MAX_SAVINGS_ACC))
            {
                if(temp->bank.sav_ac_no==Bank_account_no)
            {   
                flag=1;
                printf("Account Holder name is : %s\n",temp->cust.name);
                printf("Your account's balance is :₹ %d\n",temp->bank.balance);
                VLD_AMT:
                printf("Enter Withdrawal amount for a Savings account [Limt Rs.:- (1 > 1,00,000) within a day] : ");
                scanf("%ld",&amount);
                if( temp->bank.balance > amount )
                {
                    temp->bank.balance=( temp->bank.balance - amount );
                    printf("-----------------------------* Balance Withdrawaled Successfully *-----------------------------\n");
                    printf("Your account's current balance is :₹ %ld\n",temp->bank.balance);
                    printf("----------------------------------------*----------------------------------------\n");
                    break;
                }
                else
                {
                    printf("Insufficient Balance..!!\n");
                    goto VLD_AMT;
                }
            }
        }
            else if((Bank_account_no>=MIN_CURRENT_ACC)&&(Bank_account_no<=MAX_CURRENT_ACC))
            {
            if(Bank_account_no==temp->bank.cur_ac_no)
            {
                flag=1;
                printf("Account Holder name is : %s\n",temp->cust.name);
                printf("Your current balance is :₹ %d\n",temp->bank.balance);
                printf("Enter Withdrawal amount for a Current account [Limt Rs.:- (1 > unlimited) within a day] : ");
                scanf("%ld",&amount);
                if( temp->bank.balance > amount )
                {
                    temp->bank.balance=( temp->bank.balance - amount );
                    printf("-----------------------------* Balance Withdrawaled Successfully *-----------------------------\n");
                    printf("Your current balance is : ₹ %ld\n",temp->bank.balance);
                    printf("----------------------------------------*----------------------------------------\n");
                    break;
                }
                else
                {
                    printf("Insufficient Balance..!!\n");
                    goto VLD_AMT;
                }
            }
        }
            if(flag == 0)
            {
                printf("Account number not found,Either this bank Account doesnt belong to this bank\n");
            }
            temp=temp->next;
        }
}
    


void DepositeBalance()
{
    printf("\n------------------------------------------Deposite Balance------------------------------------------\n");
    unsigned long long int Bank_account_no;
    temp=head;
    printf("Enter the Bank account no:");
    scanf("%llu", &Bank_account_no);
        while(temp!=NULL)
        {
            long int depositeamount=0;
            if((Bank_account_no>=MIN_SAVINGS_ACC)&&(Bank_account_no<=MAX_SAVINGS_ACC))
            {
                if(temp->bank.sav_ac_no==Bank_account_no)
                {
                    printf("Account Holder name is : %s\n",temp->cust.name);
                    printf("Your account's balance is :₹ %d\n",temp->bank.balance);
                VLD_AMT:
                printf("Enter Deposite amount for a Savings account [Limt Rs.:- (1 > 1,00,000) within a day] : ");
                scanf("%ld",&depositeamount);
                    temp->bank.balance=( temp->bank.balance + depositeamount );
                    printf("Balance Deposited Successfully\n");
                    printf("Current balance : %ld\n",temp->bank.balance);
                    break;
                }
            }
            else if((Bank_account_no>=MIN_CURRENT_ACC)&&(Bank_account_no<=MAX_CURRENT_ACC))
            {
                if(temp->bank.cur_ac_no==Bank_account_no)
                {
                    printf("Account Holder name is : %s\n",temp->cust.name);
                    printf("Your account's balance is :₹ %d\n",temp->bank.balance);
                    printf("Enter Deposite amount for a current account [Limt Rs.:- (1 > 10,00,00,000) within a day] : ");
                    scanf("%ld",&depositeamount);
                    temp->bank.balance=( temp->bank.balance + depositeamount );
                    printf("Balance Deposited Successfully\n");
                    printf("Current balance : %ld\n",temp->bank.balance);
                    break;
                }
            }
            else
            {
                printf("Account number Not found..\n");
            }
            temp=temp->next;
        }
}

void Loan()
{
    printf("Take all these list of documents to the Bank Manager");
    printf("1.  Identity Proof: Passport / Aadhaar card / PAN card / driver's license / voter ID, or similar.\n");
    printf("2.  Address Proof: Utility bills / passport / bank statement / rental agreement.\n");
    printf("3.  Income Proof:-");
    printf("      (a) Salaried individuals: Salary slips (last few months), bank statements showing salary credits, and potentially Form 16 or a salary certificate.\n");
    printf("      (b) Self-employed individuals: Income tax returns, business bank statements, and possibly other financial documents.\n");
    printf("4.  Credit Score: A good credit score is crucial for loan approval, often requiring a score above 700 or 720.\n");
    printf("5.  Application Form: A completed and signed application form with personal details and loan information.\n");
    printf("6.  Photograph: Recent passport-sized photographs.\n");
    printf("7.  Bank Statements: Statements for the last few months, showing salary credits and overall transaction history.\n");
}

void balanceTransfer()
{
    unsigned long long int source_Bank_account_no=0;
    unsigned long long int desti_Bank_account_no=0;
    long int deduct=0;
    temp=head;
    printf("Enter the (Source) Bank account no: ");
    scanf("%llu", &source_Bank_account_no);   

    while(temp!=NULL)
    {
    if((source_Bank_account_no>=MIN_SAVINGS_ACC)&&(source_Bank_account_no<=MAX_SAVINGS_ACC))
            {
                if(temp->bank.sav_ac_no==source_Bank_account_no)
            {
                printf("Account Holder name is : %s\n",temp->cust.name);
                printf("Your account's balance is :₹ %d\n",temp->bank.balance);
                break;
            }
        }
            else if((source_Bank_account_no>=MIN_CURRENT_ACC)&&(source_Bank_account_no<=MAX_CURRENT_ACC))
            {
            if(source_Bank_account_no==temp->bank.cur_ac_no)
            {
                printf("Account Holder name is : %s\n",temp->cust.name);
                printf("Your current balance is :₹ %d\n",temp->bank.balance);
                break;
            } //if block
            } //else if

            temp=temp->next;
        }

            printf("Enter the (Destination) Bank account no: ");
            scanf("%llu", &desti_Bank_account_no);
            new=head;
            while(new!=NULL)
        {
            if((desti_Bank_account_no>=MIN_SAVINGS_ACC)&&(desti_Bank_account_no<=MAX_SAVINGS_ACC))
            {
                if(new->bank.sav_ac_no==desti_Bank_account_no)
            {
                printf("Account Holder name is : %s\n",new->cust.name);
                printf("Your account's balance is :₹ %d\n",new->bank.balance);
                break;
            }
            }
            else if((desti_Bank_account_no>=MIN_CURRENT_ACC)&&(desti_Bank_account_no<=MAX_CURRENT_ACC))
            {
            if(desti_Bank_account_no==new->bank.cur_ac_no)
            {
                printf("Account Holder name is : %s\n",new->cust.name);
                printf("Your current balance is :₹ %d\n",new->bank.balance);
                break;
            }   
            }
            new=new->next;
        }
        printf("Enter the transfer amount : ");
        scanf("%ld",&deduct);
        
                if( temp->bank.balance > deduct ) 
                {
                    new->bank.balance=( new->bank.balance + deduct);
                    printf("-----------------------------Balance transfered to the account succesfully (Destination)-----------------------------\n");
                    printf("Destination A/C No: %llu\tCurrent balance is :%lu\n",new->bank.sav_ac_no,new->bank.balance);
                    temp->bank.balance=( temp->bank.balance - deduct );
                    printf("-----------------------------After Balance transfered current balance (Source)-----------------------------\n");
                    printf("Source A/C No: %llu\tCurrent balance is :%lu\n",temp->bank.cur_ac_no,temp->bank.balance);
                    printf("-----------------------------Thank You for using BLACK AND WHITE Bank pvt ltd-----------------------------\n");
                }
                else
                {
                    printf("Insufficient Balance..!!\n");
                }
        
}

void deleteAccount()
{
    printf("-------------------------------------------Delete Account-------------------------------------------\n");
    printf("-------------------------------------------Delete Account-------------------------------------------\n");
    unsigned long long int Bank_account_no;
    temp=head;
    printf("Enter the Bank account number : ");
    scanf("%llu",&Bank_account_no);

    while(temp!=NULL)
    {
        if((Bank_account_no>=MIN_SAVINGS_ACC)&&(Bank_account_no<=MAX_SAVINGS_ACC))
        {
            if(Bank_account_no==MIN_SAVINGS_ACC)
            {
                temp=head;
                head=head->next;
                printf("deleted the account no. : %d",temp->bank.sav_ac_no);
                free(temp);
                break;
            }
            else
            {
                temp=head;
            
                while ((temp->bank.sav_ac_no == 0) || (temp->bank.sav_ac_no <Bank_account_no))
                {
                    previous=temp;
                    temp=temp->next;
                }
                previous->next=temp->next;
                free(temp);
                break;
            }
        }
        else if((Bank_account_no>=MIN_CURRENT_ACC)&&(Bank_account_no<=MAX_CURRENT_ACC))
        {
            if(Bank_account_no==MIN_CURRENT_ACC)
            {
                temp=head;
                head=head->next;
                printf("deleted the account no. : %d",temp->bank.cur_ac_no);
                free(temp);
                break;
            }
            else
            {
                temp=head;
                while ((temp->bank.cur_ac_no == 0) || (temp->bank.cur_ac_no <Bank_account_no))
                    {
                        previous=temp;
                        temp=temp->next;
                    }
                previous->next=temp->next;
                free(temp);
                break;
            }
        }
        else
        {
            printf("Invalid Bank account..!");
        }
    
    }
}

void BalanceEnquiry() 
{
    printf("\n------------------------------------------Withdrawal Balance------------------------------------------\n");
    unsigned long long int Bank_account_no=0;
    temp=head;
    printf("Enter the Bank account no: ");
    scanf("%llu", &Bank_account_no);
    int flag=0;

        while(temp!=NULL)
        {
            long int amount=0;
            if((Bank_account_no>=MIN_SAVINGS_ACC)&&(Bank_account_no<=MAX_SAVINGS_ACC))
            {
                if(temp->bank.sav_ac_no==Bank_account_no)
                {   
                printf("Savings Account Number is : %llu\n",Bank_account_no);
                printf("Account Holder name is : %s\n",temp->cust.name);
                printf("Your account's balance is :₹ %d\n",temp->bank.balance);
                break;
                }
            }
            else if((Bank_account_no>=MIN_CURRENT_ACC)&&(Bank_account_no<=MAX_CURRENT_ACC))
            {
            if(Bank_account_no==temp->bank.cur_ac_no)
                {
                printf("Current Account Number is : %llu\n",Bank_account_no);
                printf("Account Holder name is : %s\n",temp->cust.name);
                printf("Your current balance is :₹ %d\n",temp->bank.balance);
                break;
                }
            }
        }
}

void Save()
{
    FILE *fp;
    fp=fopen("All_Account_Details.txt","a+");
    if(fp==NULL)
    {
        printf("Not able to open database file \n");
    }
    head=NULL;
    size_t size = fwrite(new,sizeof(accountdetails), 1, fp);

    printf("Size= %u\n",size);
    if(head==NULL)
    {
        head=temp=new;
    }
    else
    {
        temp->next=new;
        temp=new;
    }
    if(size > 0)
    {
        printf("String written successfully");
    }
}

void Load()
{
    FILE *fp = fopen("All_Account_Details.txt", "rb");
    if (fp == NULL) {
        printf("Data base not yet created.\n");
        return;
    }
    head = NULL;
    while (fread(temp, sizeof(accountdetails), 1, fp)) 
    {
        new = (accountdetails *)malloc(sizeof(accountdetails));
        new->next=NULL;
        if (new == NULL)
        {
            perror("Memory allocation failed");
            fclose(fp);
            return;
        }
    if(head==NULL)
    {
        head=temp=new;
    }
    else
    {
            
            printf("\n---------------------------------------Account Holder details---------------------------------------\n");
           // printf("Customer No : %d\n",count);
            printf("Account Holder Name : %s\n",temp->cust.name);
            printf("Account Holder Address : %s\n",temp->cust.address);
            printf("Account Holder Aadhaar_id : %llu\n",temp->cust.Aadhaar_id);
            printf("Account Holder Pan_id : %s\n",temp->cust.pan_id);
            printf("Account Holder Mob_no : %llu\n",temp->cust.mob_no);
            printf("Account Holder Age : %d\n",temp->cust.age);
            // printf("\n---------------------------------------Account Holder Nominee details---------------------------------------\n");

            // printf("Account Holder Nominee Name : %s\n",new->cust.name);
            // printf("Account Holder Nominee Address : %s\n",new->cust.address);
            // printf("Account Holder Nominee Aadhaar_id : %llu\n",new->cust.Aadhaar_id);
            // printf("Account Holder Nominee Pan_id : %s\n",new->cust.pan_id);
            // printf("Account Holder Nominee Mob_no : %llu\n",new->cust.mob_no);
            // printf("Account Holder Nominee Age : %d\n",new->cust.age);

        temp->next=new;
        temp=new;
    }
        
    }

    fclose(fp);
    printf("Accounts loaded successfully!\n");
}
