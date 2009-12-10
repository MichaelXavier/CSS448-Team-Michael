#!/usr/bin/env ruby
class IntSet
  attr_reader :set_members, :largest#DEBUG
  def initialize(*vals)
    vals.reject! {|v| !v.is_a? Fixnum or v < 0}
    @set_members = [false]
    @largest = vals.max || 0
    0.upto(@largest) {|i| @set_members[i] = vals.include? i}
  end
  def +(other)
    ret = other.dup
    true_indices.each {|i| ret.insert i}
    ret
  end
  def *(other)
    IntSet.new(*true_indices.find_all {|i| other.isInSet i})
  end
  def -(other)
    IntSet.new(*true_indices.reject {|i| other.isInSet i})
  end
  def ==(other)
    true_indices.all? {|i| other.isInSet i}
  end
  def isEmpty
    @largest == 0
  end
  def isInSet(num)
    (num >= 0 and !@set_members[num].nil?) ? @set_members[num] : false
  end
  def insert(num)
    return false unless num >= 0
    if num > @largest
      (@largest + 1).upto(num - 1) {|i| @set_members[i] = false}
      @largest = num
    end
    @set_members[num] = true
  end
  def remove(num)
    return false unless num >= 0 and num <= @largest
    @set_members[num] = false  
    true
  end
  def to_s
    "{#{true_indices.collect {|i|" #{i}"}}}"
  end
private
  def true_indices
    (0..@largest).find_all {|i| @set_members[i]}
  end
end
