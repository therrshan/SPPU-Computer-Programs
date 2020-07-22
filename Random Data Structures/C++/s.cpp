# include <cstdlib>
# include <iostream>
# include <cmath>
# include <ctime>
# include <omp.h>
include <chrono>
using namespace std::chrono;
 

auto start = high_precission_clock::now();

using namespace std;

int main ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for MXM_OPENMP.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    13 October 2011
//
//  Author:
//
//    John Burkardt
//
{
  double a[500][500];
  double angle;
  double b[500][500];
  double c[500][500];
  int i;
  int j;
  int k;
  int n = 500;
  double pi = 3.141592653589793;
  double s;
  int thread_num;
  double wtime;

  timestamp ( );

  cout << "\n";
  cout << "MXM_OPENMP:\n";
  cout << "  C++/OpenMP version\n";
  cout << "  Compute matrix product C = A * B.\n";

  thread_num = omp_get_max_threads ( );

  cout << "\n";
  cout << "  The number of processors available = " << omp_get_num_procs ( ) << "\n";
  cout << "  The number of threads available    = " << thread_num <<  "\n";

  cout << "  The matrix order N                 = " << n << "\n";
//
//  Loop 1: Evaluate A.
//
  s = 1.0 / sqrt ( ( double ) ( n ) );

  wtime = omp_get_wtime ( );

# pragma omp parallel shared ( a, b, c, n, pi, s ) private ( angle, i, j, k )
{
  # pragma omp for
  for ( i = 0; i < n; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      angle = 2.0 * pi * i * j / ( double ) n;
      a[i][j] = s * ( sin ( angle ) + cos ( angle ) );
    }
  }
//
//  Loop 2: Copy A into B.
//
  # pragma omp for
  for ( i = 0; i < n; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      b[i][j] = a[i][j];
    }
  }
//
//  Loop 3: Compute C = A * B.
//
  # pragma omp for
  for ( i = 0; i < n; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      c[i][j] = 0.0;
      for ( k = 0; k < n; k++ )
      {
        c[i][j] = c[i][j] + a[i][k] * b[k][j];
      }
    }
  }

}
auto stop = high_precission_clock()::now;
 auto duration = duration_cast<microseconds>(stop - start);
 
// To get the value of duration use the count()
// member function on the duration object
cout << duration.count() << endl;
//
//  Terminate.

  

  return 0;
}
//****************************************************************************80


