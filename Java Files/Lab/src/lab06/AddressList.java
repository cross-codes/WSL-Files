package lab06;

public class AddressList {
  public static int countAddressWithCity(Address[] addressList, String city) {
    if (addressList == null || city == null || addressList.length == 0 || city.length() == 0)
      return -1;
    int cnt = 0;
    for (int i = 0; i < addressList.length; i++) {
      if (addressList[i].getCity().equals(city)) cnt++;
    }
    return cnt;
  }

  public static int countAddressWithPin(Address[] addressList, String pin) {
    if (addressList == null || pin == null || addressList.length == 0 || pin.length() == 0)
      return -1;
    int cnt = 0;
    for (int i = 0; i < addressList.length; i++) {
      if (addressList[i].getPin().equals(pin)) cnt++;
    }
    return cnt;
  }

  public static Address[] getAddressWithCity(Address[] addressList, String city) {
    if (addressList == null || city == null || addressList.length == 0 || city.length() == 0)
      return null;

    Address[] res = new Address[addressList.length];
    int iterator = 0;

    for (int i = 0; i < addressList.length; i++) {
      if (addressList[i].getCity().equals(city)) res[iterator++] = addressList[i];
    }
    if (iterator == 0) return null;
    else return res;
  }

  public static Address[] getAddressWithPin(Address[] addressList, String pin) {
    if (addressList == null || pin == null || addressList.length == 0 || pin.length() == 0)
      return null;

    Address[] res = new Address[addressList.length];
    int iterator = 0;

    for (int i = 0; i < addressList.length; i++) {
      if (addressList[i].getPin().equals(pin)) res[iterator++] = addressList[i];
    }
    if (iterator == 0) return null;
    else return res;
  }
}
