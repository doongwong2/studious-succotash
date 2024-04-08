int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize) {
    int count[2] = {0};

    for(int i =0;i < studentsSize;i++)
        count[students[i]]++;

    int remaining = sandwichesSize;

    for(int i =0;i < sandwichesSize;i++)
    {
        if(count[sandwiches[i]] == 0) break;
        if(remaining == 0) break;
        count[sandwiches[i]]--;
        remaining--;
    }

    return remaining;
}
