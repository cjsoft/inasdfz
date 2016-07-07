type data=record x,t:longint;end;
var e:array[0..2010]of data;
	ins,vis:array[0..2010]of boolean;
	last,a,b:array[0..2010]of longint;
	s:array[0..1,0..2010]of longint;
	top:array[0..1]of longint;
		n,casenum:longint;

procedure re;
begin
	assign(input,'probe.in');reset(input);
	assign(output,'probe.out');rewrite(output);
end;

procedure wr;
begin
	close(input);close(output);
end;

procedure start;
var	i:longint;
	c:char;
begin
	fillchar(ins,sizeof(ins),false);fillchar(vis,sizeof(vis),false);
	readln(n);
	for i:=1 to n do
	begin
		read(c);if c='E' then a[i]:=0 else a[i]:=1;readln(b[i]);
	end;
end;

function valid:boolean;
var	i:longint;
	h:array[0..1]of longint;
begin
	h[0]:=0;h[1]:=0;
	for i:=1 to n do
	begin
		if a[i]=0 then
			if b[i]<>0 then
			begin
				if not vis[b[i]] then vis[b[i]]:=true
				else if h[1]>0 then begin vis[b[i]]:=true;dec(h[1]);end else exit(false);
			end else inc(h[0])
			else
			if b[i]<>0 then
			begin
				if vis[b[i]] then begin vis[b[i]]:=false;ins[b[i]]:=true;end
				else if not ins[b[i]] then ins[b[i]]:=true
				else if h[0]>0 then begin vis[b[i]]:=false;dec(h[0]);end else exit(false);
			end	else inc(h[1]);
	end;
	exit(true);
end;

operator <(a,b:data)c:boolean;begin c:=a.x<b.x;end;

procedure sort(l,r:longint);
var	i,j:longint;
	x,y:data;
begin
	i:=l;j:=r;x:=e[(l+r)>>1];
	repeat
		while e[i]<x do inc(i);while x<e[j] do dec(j);
		if i<=j then begin y:=e[i];e[i]:=e[j];e[j]:=y;inc(i);dec(j);end;
	until i>j;
	if i<r then sort(i,r);if l<j then sort(l,j);
end;

procedure solve;
var	i,j,t,ans,m:longint;
begin
	fillchar(vis,sizeof(vis),false);fillchar(ins,sizeof(ins),false);
	for i:=1 to n do
	begin
		t:=a[i];if b[i]=0 then begin inc(top[t]);s[t,top[t]]:=i;end
		else if a[i]=0 then
			begin
				if not vis[b[i]] then vis[b[i]]:=true
				else begin vis[b[i]]:=true;dec(top[1]);last[b[i]]:=i;end
			end
			else
			begin
				if vis[b[i]] then begin vis[b[i]]:=false;ins[b[i]]:=true;end
				else if not ins[b[i]] then ins[b[i]]:=true
				else begin vis[b[i]]:=false;dec(top[0]);end
			end;
	end;
	j:=0;
	for t:=0 to 1 do
	for i:=1 to top[t] do
	begin inc(j);e[j].t:=t;e[j].x:=s[t,i];end;
	for i:=1 to 2000 do if last[i]<>0 then begin inc(j);e[j].t:=0;e[j].x:=last[i];end;
	m:=j;sort(1,m);ans:=0;
	for i:=1 to m do
	if e[i].t=0 then inc(ans) else if ans>0 then dec(ans);
	writeln(ans);
end;

begin
	re;
	readln(casenum);
	for casenum:=1 to casenum do
	begin
		start;
		if valid then solve
		else writeln('OTHER');
	end;
	wr;
end.
