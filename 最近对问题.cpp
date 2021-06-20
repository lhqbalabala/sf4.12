#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
struct point {
	double x,y;
} p[maxn];
int a[maxn];
int cmpxy(point a,point b) {
	if(a.x==b.x)return a.y<b.y;
	return a.x<b.x;
}
int cmpy(int &a,int &b) {
	return p[a].y<p[b].y;
}
double dist(point a,point b) {
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double closeset(int l, int r) {
	if(l==r)return 1e8+10;
	if(r==l+1)return dist(p[l],p[r]);
	int mid=(l+r)>>1;
	double ans=min(closeset(l,mid),closeset(mid+1,r));
	int cot=0;
	for(int i=l; i<=r; i++) {
		if(p[mid].x-ans<=p[i].x&&p[i].x<=p[mid].x+ans) {
			a[cot++]=i;
		}
	}
	sort(a,a+cot,cmpy);
	for(int i=0; i<cot; i++) {
		for(int j=i+1; j<cot; j++) {
			if(p[a[j]].y-p[a[i]].y>ans)break;
			ans=min(dist(p[a[i]],p[a[j]]),ans);
		}
	}
	return ans;
}
int main() {
	double minn;
	int n;
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>p[i].x>>p[i].y;
	}
	sort(p,p+n,cmpxy);
	minn=closeset(0, n-1);
	printf("%.5lf",minn);
}
/*
15
5 10
9 1
10 12
10 19
13 15
15 19
16 20
19 9
24 0
24 12
31 32
32 24
38 29
40 56
45 23*/
