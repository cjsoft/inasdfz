var	head,tail:longint;
	a:array[0..1000010]of longint;

procedure re;
begin
	assign(input,'yi.in');reset(input);
	assign(output,'yi.out');rewrite(output);
end;

procedure wr;
begin
	close(input);close(output);
end;

procedure start;
var	i:longint;
	s:ansistring;
begin
	fillchar(a,sizeof(a),0);
	readln(s);tail:=length(s);for i:=1 to tail do a[i]:=ord(s[tail-i+1])-ord('0');head:=1;
end;

procedure swap(var a,b:longint);var c:longint;begin c:=a;a:=b;b:=c;end;

procedure solve;
var	ans,x,y,i:longint;
begin
	ans:=0;
	while tail<>head do
	begin
		if a[head]=0 then inc(head) else
		begin
			for i:=head to tail do a[i]:=a[i]*3;inc(a[head]);
			for i:=head to tail+1 do begin inc(a[i+1],a[i]>>1);a[i]:=a[i]and 1;end;
			inc(tail);if a[tail+1]<>0 then inc(tail);
		end;
		inc(ans);
	end;
	writeln(ans);
end;

begin
	re;
	start;
	solve;
	wr;
end.
