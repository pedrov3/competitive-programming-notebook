s.insert(1);
s.insert(2);
s.insert(4);
s.insert(8);
s.insert(16);

cout << *s.find_by_order(1) << endl;             // 2
cout << *s.find_by_order(2) << endl;             // 4
cout << *s.find_by_order(4) << endl;             // 16
cout << (end(s) == s.find_by_order(6)) << endl;  // true

cout << s.order_of_key(-5) << endl;   // 0
cout << s.order_of_key(1) << endl;    // 0
cout << s.order_of_key(3) << endl;    // 2
cout << s.order_of_key(4) << endl;    // 2
cout << s.order_of_key(400) << endl;  // 5
