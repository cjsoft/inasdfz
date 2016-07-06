const lim=1000000000;
var	a:array[0..1,0..2010]of longint;
	b:array[0..2010]of longint;
	root:array[0..1]of int64;
	sum,lc,rc:array[0..3300000]of int64;
	cnt,n,m:longint;

procedure re;
begin
	assign(input,'name.in');reset(input);
	assign(output,'name.out');rewrite(output);
end;

procedure wr;
begin
	close(input);close(output);
end;

procedure swap(var a,b:int64);var c:int64;begin c:=a;a:=b;b:=c;end;

procedure start;
var	i,x:longint;
begin
	readln(n);
end;

procedure solve1;
var	i,l,r,t,j:longint;
	ans:int64;
begin
	for i:=1 to n do begin read(a[0,i]);b[i]:=0;end;
	for i:=1 to n do read(a[1,i]);
	readln(m);ans:=0;
	for i:=1 to m do
	begin
		readln(l,r,t);
		for j:=l to r do
		if a[b[j],j]<=t then b[j]:=b[j] xor 1;
	end;
	for i:=1 to n do inc(ans,a[b[i],i]);
	writeln(ans);
end;

procedure clean2;
begin
	cnt:=0;
	root[0]:=0;root[1]:=0;
	sum[0]:=0;lc[0]:=0;rc[0]:=0;
end;

procedure insert(var now:int64;l,r,x:longint);
var	mid:longint;
begin
	if now=0 then begin inc(cnt);now:=cnt;end;
	inc(sum[now],x);if l=r then exit;mid:=(l+r)>>1;
	if x<=mid then insert(lc[now],l,mid,x) else insert(rc[now],mid+1,r,x);
end;

procedure shift(d1,d2:longint);
begin
	swap(sum[d1],sum[d2]);
	swap(lc[d1],lc[d2]);swap(rc[d1],rc[d2]);
end;

procedure update(x:longint);begin sum[x]:=sum[lc[x]]+sum[rc[x]];end;

procedure change(d1,d2:int64;l,r,x:longint);
var	mid:longint;
begin
	if r=x then begin shift(d1,d2);exit;end;mid:=(l+r)>>1;
	if x>mid then change(rc[d1],rc[d2],mid+1,r,x);change(lc[d1],lc[d2],l,mid,x);
	update(d1);update(d2);
end;

procedure solve2;
var	i,l,r,x:longint;
begin
	clean2;
	for i:=1 to n do begin read(x);insert(root[0],0,lim,x);end;
	for i:=1 to n do begin read(x);insert(root[1],0,lim,x);end;
	readln(m);
	for i:=1 to m do
	begin
		readln(l,r,x);
		change(root[0],root[1],0,lim,x);
	end;
	writeln(sum[root[0]]);
end;

begin
	re;
	start;
	if n<=2000 then solve1{ else solve2};
	wr;
end.
