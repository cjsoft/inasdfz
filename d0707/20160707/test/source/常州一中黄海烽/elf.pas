var
   a,c,b:array[0..100] of int64;
   s:array[0..100] of string;
   ss:string;
   n,l,i,j,cc:longint;ans:int64;

procedure setin;
begin
    assign(input,'elf.in');
    assign(output,'elf.out');
    reset(input);rewrite(output);
end;

procedure outit;
begin
    close(input);close(output);
end;

function check(tmp:int64):boolean;
var i,j:longint;p:boolean;
begin
    for cc:=1 to 40 do begin c[cc]:=tmp and 1;tmp:=tmp>>1;end;
    for i:=40 downto length(ss) do
    begin
        p:=true;
        for j:=1 to length(ss) do
         if c[i-j+1]<>b[j] then begin p:=false;break;end;
        if p then exit(true);
    end;
    exit(false);
end;

procedure dfs(now:longint;tmp:int64);
begin
    if now=n+1 then
    begin
        if check(tmp) then inc(ans);
        exit;
    end;
    dfs(now+1,tmp);
    dfs(now+1,tmp xor a[now]);
end;

begin
    setin;
    readln(n);
    for i:=1 to n do readln(s[i]);
    readln(l);
    readln(ss);
    for i:=1 to n do
    begin
        a[i]:=0;
        for j:=1 to length(s[i]) do a[i]:=a[i]*2+ord(s[i][j])-48;
    end;
    for i:=1 to length(ss) do b[i]:=ord(ss[i])-48;
    ans:=0;dfs(1,0);writeln(ans);
    outit;
end.