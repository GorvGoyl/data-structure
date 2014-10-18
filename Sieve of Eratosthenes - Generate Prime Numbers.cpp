On my previous post Basic Primality Test I discussed about how to check if a number N is Prime or not. We  came to O(vn) solution for testing prime numbers. On this post we are going to develop a better solution. For that we are going to need Sieve of Eratosthenes.

If you have never heard about Sieve of Eratosthenes, you may want to read the Wikipedia page on Sieve of Eratosthenes first. It will help you understand better what I am going to discuss.

A prime number is a number which is only divisible by 1 and itself. So what about a number which is a multiple of the prime. For example, 7 is prime but 21 ( 7 * 3 ) is not a prime. If a number P is prime, then all of its multiples k*P ( where k > 1 ) are not prime. This is the basic concept of Sieve of Eratosthenes.

Next, the purpose of the Sieve of Eratosthenes. Why do we use it? We use Sieve of Eratosthenes to generate all prime numbers from 1 to N. That's it.

With those two points out of our way, we are going to now start with problem and derive a solution.

Problem: Given a value N, generate all the Prime numbers from 1 to N.

First, let us see if we can solve the problem with the O(vn) solution we already know. Suppose the value of N is 10,000,000. Then for each value x from 1 to N we will have to check from 1 to vx. For simplification let us consider the complexity be N*vN. Then it will take around 316 seconds to calculate. In most cases we consider it slow.

We can however generate this prime numbers in much faster way using Sieve of Eratosthenes.

Sieve of Eratosthenes

For ease of understanding, suppose the value of N is 20. Now, imagine we have all the numbers from 1 to 20 line up inside a tube ( sieve ) like this:

0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20

Now, I am going to simulate what Sieve of Eratosthenes is going to do for use in our program.

First of all, we know 0 and 1 are not prime numbers. So we can cut them off from the sieve.

x x 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20

Now we iterate from left to right inside the sieve. Any number which has not been cut off yet is a prime. Following that rule, the first number which has not been cut off yet in the list is 2. So 2 is a prime. We know that any multiple of 2 is not a prime. So let us cut them off.

x x 2 3 x 5 x 7 x 9 x 11 x 13 x 15 x 17 x 19 x

Next is 3. Its a prime since it is not cut off yet. So now our sieve will look like

x x 2 3 x 5 x 7 x 9 x 11 x 13 x x x 17 x 19 x

We continue to do this till we reach end of the sieve. After that, all the numbers that remain are still prime numbers.

This is how we perform the algorithm on paper with pen. Now we need to convert this concept into programming code and perform it efficiently. But for now, let's just forget about efficiency and simply code.

Normal Code of Sieve of Eratosthenes
char stat[10000000]; //The size depends on N.
//Initially value of stat[] is 0.
//0 means prime and 1 means not prime

void sieve ( int N )
{
    stat[0] = 1;
    stat[1] = 1;//They are not prime
    
    int i, j;
    for ( i = 0; i <= N; i++ )
    {
        if ( stat[i] == 0 ) //It is a prime
        {
            for ( j = i + i; j <= N; j += i ) /*Start from ( i + i ) since i is prime.*/
            {
                stat[j] = 1; // Multiple is not prime
            }
        }
    }
    
    //Print the prime
    for ( i = 0; i <= N; i++ )
    {
        if ( stat[i] == 0 ) printf ( "%d\n", i );
    }
}
The size of status ( stat ) array depends on the size of N. After that we set stat[0] and stat[1] into 1 since they are not prime. After that we simple start a loop from 0 to N ( end of the sieve ) and whenever we find a prime, we cut of its multiple. After that at the end, we print all the primes.

I am sure that even you can see that this code is not optimized. For example, there was no need to start from 0. We could have started from 2. Other than this there are several more optimizations. We will now look at the optimizations.

Optimizations of Sieve of Eratosthenes Code:

Our first optimization would be removal of the even numbers. We all know that 2 is the only even prime number since any other even number is divisible by 2. Then, do we really need to check other even numbers for whether they are prime numbers or not? No we don't .

Few more things we know are:

*Sum of two Even number is Even.
*Sum of two Odd number is Even
*Sum of Even and Odd number is Odd

For example, 3. 3 is a prime and look at its multiples.

3 6 9 12 15 18 21 ....

Its multiple is found by adding 3 with each number. We start with 3 and add 3. Odd + Odd make it Even (6). Then we add 3 with 6 and Odd + Even makes it Odd (9).  This keeps on repeating itself. Since we are trying to remove the even numbers, we can simply add 2 * 3 ( 6 ) with each number. Odd + Even will keep
it Odd in each step.

3 + 6 = 9
9 + 6 = 15
15 + 6 = 21

Now, using this information, we can rewrite our code into this:
char stat[10000000]; 
void sieve ( int N )
{
    stat[0] = 1;
    stat[1] = 1;
    
    int i, j;

    for ( i = 4; i &lt;= N; i += 2 ) //Remove even numbers
    {
        stat[i] = 1;
    }
    
    //2 is already a prime
    //Only check the odd numbers
    //Odd + Even is Odd
    for ( i = 3; i &lt;= N; i += 2 )
    {
        if ( stat[i] == 0 )
        {
            //Start from ( i + 2 * i ) since i is prime
            //and i + i is even;
            
            //Since j starts with odd number
            //we keep it odd by adding even number
            //2 * i;
            for ( j = i * 3; j &lt;= N; j += 2 * i ) 
            {
                stat[j] = 1; 
            }
        }
    }
    
    printf ( "2\n" );
    for ( i = 3; i &lt;= N; i += 2 )
    {
        if ( stat[i] == 0 ) printf ( "%d\n", i );
    }
}
For our next optimization we have to observe few things.

Say we have a sieve from 1 to 50. Then our sieve will look like this at first:

x x 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50

After removing even numbers it will look like this:

x x 2 3 x 5 x 7 x 9 x 11 x 13 x 15 x 17 x 19 x 21 x 23 x 25
x 27 x 29 x 31 x 33 x 35 x 37 x 39 x 41 x 43 x 45 x 47 x 49 x

Now, lets assume we have cut off multiples of 3 and 5 from the sieve. Then our sieve will look like this:

x x 2 3 x 5 x 7 x x x 11 x 13 x x x 17 x 19 x x x 23 x x
x x x 29 x 31 x x x x x 37 x x x 41 x 43 x x x 47 x 49 x

Now, we have come to 7. See what happens when we try to cancel out multiple of 7. We start from 21 ( we skip 14 since it is even ), but 21 is already cut of by 3 ( 3 * 7= 21 ). So we move to 35 but it is also cut off by some other prime ( 5 * 7 = 35 ). Then we move to 49 and find that it has not been cut off. How can it be? Its factor is 7 only ( 7 * 7 = 49 ) and we did not work with seven before.

So for any odd number X, what should be the appropriate number to start from? Lets say we start from a multiple of X which is k*X. So what should be the value k here? If  k < X then we have already cut off  k*X before when working with small k. Then the best option would be to start from X * X.

Using this idea, our new code would be:
char stat[10000000]; 

void sieve ( int N )
{
    stat[0] = 1;
    stat[1] = 1;
    
    int i, j;

    for ( i = 4; i &lt;= N; i += 2 )
    {
        stat[i] = 1;
    }
    
    int sqrtn = sqrt ( N );
    //We iterate i till sqrt(n) since we start j
    //from i * i. And if i &gt; sqrt ( n ) then
    //j would be greater than N.
    for ( i = 3; i &lt;= sqrtn; i += 2 )
    {
        if ( stat[i] == 0 )
        {
            for ( j = i * i; j &lt;= N; j += 2 * i ) 
            {
                stat[j] = 1; 
            }
        }
    }
    
    printf ( "2\n" );
    for ( i = 3; i &lt;= N; i += 2 )
    {
        if ( stat[i] == 0 ) printf ( "%d\n", i );
    }
}

Now notice that we iterate i from 3 to vN. Since we start our j from i * i, if i > vN then j would become greater than N.

That's it for our Sieve of Eratosthenes. There is another way of calculating Sieve of Eratosthenes that involves use of bit-wise operations, which is slower but takes less space. We will discuss it later.

My Code:

The main purpose of Sieve of Eratosthenes is to generate prime numbers from 1 to N so that we can use it in other algorithms. Here is how I generate my prime numbers using sieve.
vector <int> primelist ( int n )
{
    vector <int> prime;
    vector <char> stat ( n + 10 );
    prime.push_back ( 2 );
    int i, j, sqrtn = sqrt ( n );
    for ( i = 3; i <= sqrtn; i += 2 )
    {
        if ( stat[i] == 0 )
        {
            for ( j = i * i; j <= n; j += 2 * i ) stat[j] = 1;
        }
    }
    for ( i = 3; i <= n; i += 2 ) if ( stat[i] == 0 ) prime.push_back(i);
    return prime;
}

vector <int> prime;

int main ()
{
    prime = primelist ( 1000 );
    //Now I use the prime numbers from vector prime.
    return 0; 
}

Occasionally I need the stat[] array in some other function. I simply declare it globally then :)

Reference:
1) LightOJ Training Section ( You have to register to access the site ).
