int numSteps(char* s) {
    int steps = 0;
    int size = strlen(s) - 1;
    int carry = 0, count = 0;

    while(size > 0)
    {
        if(s[size] - '0' + carry == 0)
        {
            carry = 0;
            steps++;
        }
        else if (s[size] - '0' + carry == 2)
        {
            carry = 1;
            steps++;
        }
        else
        {
            carry = 1;
            steps += 2;
        }
        size--;

    }

    if(carry == 1) steps++;
    
    return steps;
}
