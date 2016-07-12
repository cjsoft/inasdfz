type data=record x,id:longint;end;
	interval=record l,r:longint;end;
var	e:array[0..4000010]of interval;
	c:array[0..2010]of data;
	a,b:array[0..2010]of longint;
	sum:array[0..2010,0..2010]of longint;
	n,p,q,tot:longint;

procedure re;
begin
	assign(input,'lian.in');reset(input);
	assign(output,'lian.out');rewrite(output);
end;

procedure wr;
begin
	close(input);close(output);
end;

operator <(a,b:data)c:boolean;begin c:=a.x<b.x;end;

procedure sort1(l,r:longint);
var	i,j:longint;x,y:data;
begin
	i:=l;j:=r;x:=c[(l+r)>>1];
	repeat
		while c[i]<x do inc(i);while x<c[j] do dec(j);
		if i<=j then begin y:=c[i];c[i]:=c[j];c[j]:=y;inc(i);dec(j);end;
	until i>j;
	if i<r then sort1(i,r);if l<j then sort1(l,j);
end;

procedure lsh;
var	i,p:longint;
begin
	sort1(1,n);p:=0;
	for i:=1 to n do
	begin if c[i].x<>c[i-1].x then inc(p);a[c[i].id]:=p;end;tot:=p;
end;

procedure start;
var	i,j,t:longint;
begin
	readln(n,p,q);
	for i:=1 to n do begin read(b[i]);c[i].x:=b[i];c[i].id:=i;end;
	lsh;
	for i:=1 to n do
	begin
		sum[i,a[i]]:=sum[i-1,a[i]]+1;
		for j:=1 to tot do if j<>a[i] then sum[i,j]:=sum[i-1,j];
	end;
	t:=0;
	for i:=1 to n do
	for j:=i to n do begin inc(t);e[t].l:=i;e[t].r:=j;end;
end;

operator <(a,b:interval)c:boolean;
var	i:longint;
begin
	for i:=1 to tot do if (sum[a.r,i]-sum[a.l-1,i])<>(sum[b.r,i]-sum[b.l-1,i]) then break;
	if (sum[a.r,i]-sum[a.l-1,i])<>(sum[b.r,i]-sum[b.l-1,i]) then
	c:=(sum[a.r,i]-sum[a.l-1,i])>(sum[b.r,i]-sum[b.l-1,i]) else
	c:=a.l<b.l;
end;

procedure sort2(l,r:longint);
var	i,j:longint;x,y:interval;
begin
	i:=l;j:=r;x:=e[(l+r)>>1];
	repeat		
		while e[i]<x do inc(i);while x<e[j] do dec(j);
		if i<=j then begin y:=e[i];e[i]:=e[j];e[j]:=y;inc(i);dec(j);end;
	until i>j;
	if i<r then sort2(i,r);if l<j then sort2(l,j);
end;

procedure print;
var	i:longint;
begin
	for i:=p to q do writeln(e[i].l,' ',e[i].r);
end;

begin
	re;
	start;
	sort2(1,n*(n+1)>>1);
	print;
	wr;
end.
