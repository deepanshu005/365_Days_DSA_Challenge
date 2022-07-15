void main() {
  //List
  var arr1 = ['100', '200', '300'];
  arr1.forEach((x) => print(x));
  //Set
  var arr2 = {'100', '200', '300'};
  arr2.forEach((x) => print(x));
  //Map
  var arr3 = {'1': '100', '2': '200', '3': '300'};
  arr3.forEach((key, value) {
    key = value;
    print('$key : $value');
  });
}
