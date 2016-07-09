var	e,n,ans,last:longint;
	ot,ne,p:array[0..2010]of longint;
	g:array[0..1010]of longint;
	size:array[0..1010,0..1010]of longint;

procedure re;
begin
	assign(input,'network.in');reset(input);
	assign(output,'network.out');rewrite(output);
end;

procedure wr;
begin
	close(input);close(output);
end;

procedure clean;
begin
	e:=1;fillchar(g,sizeof(g),0);
end;

procedure add(x,y,z:longint);
begin
	inc(e);ot[e]:=y;ne[e]:=g[x];g[x]:=e;p[e]:=z;
	inc(e);ot[e]:=x;ne[e]:=g[y];g[y]:=e;p[e]:=z;
end;

procedure start;
var	i,x,y,z:longint;
begin
	readln(n);
	clean;
	for i:=1 to n-1 do begin readln(x,y,z);add(x,y,z);end;
end;

procedure change(x,y:longint);
begin
	p[x<<1]:=y;p[x<<1 or 1]:=y;
end;

function gcd(a,b:longint):longint;begin if b=0 then exit(a);exit(gcd(b,a mod b));end;

procedure dfs(id,fa,x,y:longint);
var	u,vj:longint;
begin
	if y=1 then begin inc(ans,size[id,x]);exit;end;
	u:=g[x];
	while u>0 do
	begin
		vj:=ot[u];
		if vj<>fa then dfs(id,x,vj,gcd(y,p[u]));
		u:=ne[u];
	end;
end;

function getans:longint;
var	i,u:longint;
begin
	ans:=0;
	for i:=1 to n do
	begin
		u:=g[i];
		while u>0 do
		begin
			dfs(i,i,ot[u],p[u]);
			u:=ne[u];
		end;
	end;
	exit(ans>>1);
end;

procedure getsize(id,fa,x:longint);
var	u,vj:longint;
begin
	size[id,x]:=1;u:=g[x];
	while u>0 do
	begin
		vj:=ot[u];
		if vj<>fa then begin getsize(id,x,vj);inc(size[id,x],size[id,vj]);end;
		u:=ne[u];
	end;
end;

procedure solve;
var i,x,y,m:longint;
begin
	for i:=1 to n do getsize(i,0,i);
	writeln(getans);
	readln(m);
	for i:=1 to m do
	begin
		readln(x,y);change(x,y);
		writeln(getans);
	end;
end;

begin
	re;
	start;
	solve;
	wr;
end.
