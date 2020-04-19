#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <string>
using namespace std;

// definitions
#define FOR(i,a,b) for( int i=(a),_n=(b); i<=_n; ++i )
#define clr(x,v) memset( x, v, sizeof(x) )
#define N 50
#define INF 1e5


// declarations
char cmd[50];
int n, user;
int S, T;

// functions
int f[N][N];
int c[N][N];

int maxflow( int n, int s, int t )
{
	static int i, u, v, flow, d[N], pre[N];
	static bool visited[N];
	flow = 0;
	clr( f, 0 );

	while( true ) {
		fill(visited, visited + N, false ); 
		fill(d, d + N, 0);
		
		queue<int> que;
		que.push(s); visited[s] = true; d[s] = INF;

		while( !que.empty() && !visited[t] ) {
			u = que.front(); que.pop();
			for( v=0; v<=n; ++v ) if( !visited[v] && f[u][v]<c[u][v] ) {
				visited[v] = true; que.push(v); pre[v] = u;

				if( d[u] < c[u][v]-f[u][v] ) d[v] = d[u];
				else d[v] = c[u][v]-f[u][v];
			}
		}

		if( !visited[t] ) break;
		flow += d[t];

		for( u=t; u!=s; ) {
			v = u; u = pre[v];
			f[u][v] += d[t];
			f[v][u] = -f[u][v];
		}
	}

	return flow;
}

void parse( char *input ) 
{
	static int l;
	static int u, num, v;

	l = strlen( input );

	u = input[0] - 'A' + 1;
	num = input[1] - '0';

	user += num;
	c[S][u] += num;

	FOR( i, 3, l-2 ) {
		c[u][input[i]-'0'+26 + 1] = 1;
	}
}

void init()
{
	clr( c, 0 );
	user = 0;
	FOR( i, 27, 36)
		c[i][T] = 1;
}

int main( void )
{
	int mf;
	int v;
	S = 0;
	T = 37;
	n = 37;
	
	while( gets(cmd) && cmd[0] ) {
		init();
		parse(cmd);

		while(gets(cmd) && cmd[0] ) 
			parse(cmd);

		mf = maxflow( n, S, T );

		if(mf != user) puts("!");
		else {
			FOR( u, 27, 36) {
				for( v=1; v<=26 && !f[v][u]; ++v );

				if( v > 26 ) cout << '_';
				else cout << (char)((v - 1) + 'A');
			}
			cout << endl;
		}
	}
	
	return 0;
}