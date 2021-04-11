var sk_card;
randomize();
if (random_range(0,10000) < 1){
    sk_card = "Ex";
    return sk_card;
}
if (random_range(0,1000) < 5){
    sk_card = "S";
    return sk_card;
}
if (random_range(0,100) < 5){
    sk_card = "A";
    return sk_card;
}
if (random_range(0,100) < 10){
    sk_card = "B";
    return sk_card;
}
if (random_range(0,100) < 65){
    sk_card = "C";
    return sk_card;
}
return "D";