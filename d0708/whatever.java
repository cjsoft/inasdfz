import java.util.*;
class Node {
  Node getNext() {
    return this;
  }
}

public class LoopInspector {

  Map mp;
  LoopInspector() {
    mp = new HashMap<Node, Integer>();
  }
  Integer find(Node nnn, Integer dep) {
    mp.put(nnn, dep);
    if (mp.containsKey(nnn.getNext())) {
      return dep - (Integer)mp.get(nnn.getNext()) + 1;
    }
    return find(nnn.getNext(), dep + 1);
  }
  public int loopSize(Node node) {
    Node nnn = node;
    return find(nnn, 1);
  }
}