var head,nxt,twd,dat:array[1..2200]of longint;
sumedge:longint;
n,q:longint;
ans:longint;
i:longint;
t1,t2:longint;

procedure add(s,t,w:longint);
begin
inc(sumedge);
nxt[sumedge]:=head[s];
head[s]:=sumedge;
twd[sumedge]:=t;
dat[sumedge]:=w;
end;

procedure add0(s,t,w:longint);
begin
add(s,t,w);
add(t,s,w);
end;

procedure init;
var t1,t2,t3:longint;
begin
sumedge:=1;
read(n);
for i:=1 to n-1 do begin
	read(t1,t2,t3);
	add0(t1,t2,t3);
	end;
read(q);
end;

procedure swap(var a,b:longint);
var t:longint;
begin
t:=a;
a:=b;
b:=t;
end;

{
function gcd(a,b:longint):longint;
begin
if (b>a) then swap(a,b);
if (b=0) then exit(a);
if (a and 1 = 1) and (b and 1 = 1) then exit(gcd(b,(a-b)>>1))
else if (a and 1 = 1) and (b and 1 = 0) then exit(gcd(a,b>>1))
else if (a and 1 = 0) and (b and 1 = 1) then exit(gcd(a>>1,b))
else exit(gcd(a>>1,b>>1));
end;
}

function gcd(a,b:longint):longint;
begin
if b=0 then exit(a) else exit(gcd(b,a mod b));
end;


procedure dfs(u,nowgcd,fa:longint);
var v,now:longint;
begin
now:=head[u];
if nowgcd=1 then inc(ans);
while now<>0 do begin
	v:=twd[now];
	if v=fa then begin
		now:=nxt[now];
		continue;
		end;
	dfs(v,gcd(dat[now],nowgcd),u);
	now:=nxt[now];
	end;
end;

procedure calc;
var i:longint;
begin
ans:=0;
for i:=1 to n do begin
	dfs(i,0,0);
	end;
writeln(ans>>1);
end;



begin
assign(input,'network.in');
assign(output,'network.out');
reset(input);
rewrite(output);
init;
//dfs(3,0,0);
calc;
for i:=1 to q do begin
	read(t1,t2);
	dat[t1<<1]:=t2;
	dat[t1<<1+1]:=t2;
	calc;
	end;
close(input);
close(output);
end.
