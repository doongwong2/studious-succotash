int min(int a , int b)
{
    if( a < b) return a;
    return b;
}

int timeRequiredToBuy(int* tickets, int ticketsSize, int k) {
    int total = 0;

    for(int i =0;i < ticketsSize;i++)
    {
        if(i <=k)
        {
            total += min(tickets[i], tickets[k]);
        }
        else
        {
            total += min(tickets[i], tickets[k] -1);
        }
    }

    return total;

}
