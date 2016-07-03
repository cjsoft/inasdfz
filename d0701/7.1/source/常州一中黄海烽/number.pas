type arr=array[0..150] of integer;
var
   nn,tmp,tt:int64;
   ans,k,i,j:longint;
   a:array[0..7001,0..150] of integer;
   b,d:arr;
   f:array[0..7001] of boolean;

procedure setin;
begin
    assign(input,'number.in');
    assign(output,'number.out');
    reset(input);rewrite(output);
end;

procedure outit;
begin
    close(input);close(output);
end;

function check(c:arr):boolean;
var i,tmp:longint;
begin
    d[0]:=0;
    while d[0]<b[0] do
    begin
        inc(d[0]);
        d[d[0]]:=c[1] and 1;
        tmp:=0;
        for i:=c[0] downto 1 do
        begin
            tmp:=tmp*10+c[i];
            c[i]:=tmp >> 1;
            tmp:=tmp and 1;
        end;
        while (c[0]>1)and(c[c[0]]=0) do dec(c[0]);
    end;
    for i:=1 to b[0] do if b[i]<>d[i] then exit(false);
    exit(true);
end;

begin
    setin;
    read(k);
    a[1,0]:=1;a[1,1]:=1; f[1]:=true;
    tt:=1;ans:=1;
    while ans<k do
    begin
        inc(tt);
        inc(ans);f[ans]:=true;
        a[ans,0]:=tt;
        a[ans,tt]:=1;if ans=k then break;
        for i:=1 to ans-1 do
        if f[i] then
        begin
            for j:=1 to a[i,0] do b[j]:=a[i,j];
            for j:=a[i,0]+1 to tt-1 do b[j]:=0;
            b[0]:=tt;b[tt]:=1;
            if check(b) then
            begin
               inc(ans);f[ans]:=true;
               for j:=0 to b[0] do a[ans,j]:=b[j];
               if ans=k then break;
            end else f[i]:=false;
        end;
    end;
    for i:=a[k,0] downto 1 do write(a[k,i]);writeln;
    outit;
end.