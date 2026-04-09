program sample;
var
    x, y, result: int;
    temperature: float;
begin
    print(10);
    read(x);
    y := x + 5;
    result := y * 2;
    print(result);
    
    if x > 0 then
        print(x);
    endif
    
    while y < 10 do
        y := y + 1;
        print(y);
    endwhile
    
    for x := 1 to 5 step 1 do
        print(x);
    endfor
end