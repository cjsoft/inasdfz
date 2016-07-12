const n=4000+10;//p:int64=1000000000+7;
var a:array[0..n,0..n]of int64;
    b1,b2,b3:longint;
    tt,nn,p:longint;
    t1,t2:text;
function ask(f1,f2:longint):int64;
begin
    if (f1<0)or(f2<0) then exit(0);
    if a[f1,f2]<>-1 then exit(a[f1,f2]);
    a[f1,f2]:=ask(f1-1,f2)*2 + ask(f2,f1-1)*int64(f1);
    a[f1,f2]:=a[f1,f2]mod p;
    exit(a[f1,f2]);

end;
begin
    assign(t1,'icefall.in');reset(t1);
    assign(t2,'icefall.out');rewrite(t2);
    fillchar(a,sizeof(a),$FF);
    read(t1,tt);
    for b1:=1 to tt do begin
        a[1,0]:=1;
        read(t1,nn,p);
        writeln(t2,ask(nn,nn)*2 mod p);
        for b2:=0 to nn do for b3:=0 to nn do a[b2,b3]:=-1;
    end;
    close(t1);
    close(t2);

end.