    for (int i = 3; i <= 100; i ++)
    {
        a[i] = a[i-1] + a[i-2];
        if (a[i] > Max)
        {
            printf("%d",i);
            return 0;
        }
    }    
    

}