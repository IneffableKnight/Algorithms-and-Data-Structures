#include <iostream>
#include <queue>

using namespace std;

struct Call
{
  Call( int callNum, long callTime, int callLength ) :
    CallNum( callNum ), CallTime( callTime ), CallLength( callLength ) { }

  int CallNum;
  long CallTime;
  int CallLength;
};

bool operator>( const Call& lhs, const Call& rhs ) {
  return lhs.CallLength > rhs.CallLength;
}

ostream& operator<<( ostream& os, const Call& c ) {
  os << c.CallNum << " " << c.CallTime << " " << c.CallLength;
  return os;
}

main()
{
  priority_queue< Call, vector<Call>, greater<Call> > q; 
  q.push( Call( 1, 200, 150 ));
  q.push( Call( 2, 300, 950 ));
  q.push( Call( 3, 100, 450 ));
  q.push( Call( 4, 150, 320 ));

  unsigned i=0, n=q.size();
  for ( i=0; i<n; ++i ) {
    cout << q.top() << endl;
    q.pop();
  }
}