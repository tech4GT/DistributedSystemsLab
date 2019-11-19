struct numbers
{
    int a;
    int b;
};

program ADD_PROG
{
    version ADD_VERS
    {
        int add(numbers) = 1; /*proc no=1*/
    }
    = 1; /*version no*/
}
= 0x31230000; /*prog no*/