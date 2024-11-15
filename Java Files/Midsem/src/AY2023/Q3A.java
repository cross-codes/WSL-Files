package AY2023;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

class Spaceship {
  private int foodOnBoard;
  private HashMap<String, Integer> crewMemberMap;
  private ArrayList<String> planetsVisited;

  public Spaceship(int x) {
    this.foodOnBoard = x;
    this.crewMemberMap = new HashMap<>();
    this.planetsVisited = new ArrayList<>();
  }

  public void board(String crewMemberName, int foodPerDay) {
    this.crewMemberMap.put(crewMemberName, foodPerDay);
  }

  public void unboard(String crewMemberName) {
    this.crewMemberMap.remove(crewMemberName);
  }

  public String getPlanetsVisited() {
    return this.planetsVisited.toString();
  }

  public boolean flyTo(String planetName, int daysRequired) {
    int requiredAmt = 0;
    for (Integer food : this.crewMemberMap.values()) requiredAmt += food * daysRequired;
    if (requiredAmt > this.foodOnBoard) return false;
    else {
      this.foodOnBoard -= requiredAmt;
      this.planetsVisited.add(planetName);
      return true;
    }
  }

  private String visitablePlanets(
      int startingFood, HashMap<String, Integer> crewMap, HashMap<String, Integer> planetMap) {
    ArrayList<String> res = new ArrayList<>();
    int foodPerDay = 0;
    for (Integer foodAmt : crewMap.values()) foodPerDay += foodAmt;
    for (Map.Entry<String, Integer> entries : planetMap.entrySet()) {
      startingFood -= entries.getValue() * foodPerDay;
      if (startingFood > 0) res.add(entries.getKey());
      else break;
    }
    return res.toString();
  }
}
