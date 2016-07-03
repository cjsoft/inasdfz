const mo=998244353;
var	f,g:array[0..1,0..30010]of int64;
	a,last:array[0..30010]of longint;
	vis:array[0..5]of boolean;
	n,m,k,casenum:longint;
	
procedure re;
begin
	assign(input,'data.in');reset(input);
	assign(output,'data.out');rewrite(output);
end;

procedure wr;
begin
	close(input);
	close(output);
end;

procedure start;
var	i:longint;
begin
	readln(n,k,m);
	for i:=1 to n do read(a[i]);
end;

procedure swap(var a,b:longint);var c:longint;begin c:=a;a:=b;b:=c;end;

function query(l,r:longint):longint;
var	i,j,x,y:longint;
	ans:int64;
begin
	ans:=0;x:=0;y:=1;
	fillchar(f,sizeof(f),0);
	fillchar(vis,sizeof(vis),false);
	for j:=1 to n do
	begin
		g[0,j]:=g[0,j-1];f[0,j]:=1;
		if not vis[a[j]] then begin vis[a[j]]:=true;inc(ans);inc(g[0,j]);end;
	end;
	for i:=2 to n do
	begin
                fillchar(f[y],sizeof(f[y]),0);
                fillchar(g[y],sizeof(g[y]),0);
		for j:=0 to k-1 do last[j]:=l-1;
		for j:=l+i-1 to r do
		begin
			f[y,j]:=g[x,j-1]{-f[y,last[a[j]]]};
                        g[y,j]:=(g[y,j-1]+f[y,j]-f[y,last[a[j]]])mod mo;
			ans:=(ans+f[y,j]-f[y,last[a[j]]])mod mo;last[a[j]]:=j;
		end;
		swap(x,y);
	end;
	exit(ans);
end;

procedure solve;
var	act,i,j,l,r,x:longint;
begin
	for j:=1 to m do
	begin
		read(act);
		case act of
		1:	begin
				readln(l,r,x);
				for i:=l to r do a[i]:=(a[i]+x)mod k;
			end;
		2:	begin
				readln(l,r,x);
				for i:=l to r do a[i]:=(a[i]*x)mod k;
			end;
		3:	begin
				readln(l,r);
				writeln(query(l,r));
			end;
		end;
	end;
end;

begin
	re;
	readln(casenum);
	for casenum:=1 to casenum do
	begin
		start;
		solve;
	end;
	wr;
end.
