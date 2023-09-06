PROGRAM fibonacci
    Integer n, i, fib(10)
    print *, "Enter a number between 3 and 10"
    read *, n

    DO WHILE(n < 3 .OR. n > 10)
            print*, "Invalid Input. Enter a valid number."
            read*, n
    END DO
    
    fib(1) = 1
    print *, fib(1)
    fib(2) = 1
    print *, fib(2)
    
    do 100 i=3, n
        fib(i) = fib(i-1) + fib(i-2)
        print *, fib(i)
100     continue

END PROGRAM fibonacci
