#ifndef FOOD_WASTAGE_TRACKER_H_
#define FOOD_WASTAGE_TRACKER_H_

#include <iostream>
#include <iterator>
#include <vector>
#include "food_wastage_record.h"
#include "food_wastage_report.h"

// Bryant Huynh
// CPSC 121L-01
// 12/01/2023
// 22bhuynh2@csu.fullerton.edu
// @bryqnt

class FoodWastageTracker {
  // ======================= YOUR CODE HERE =======================
  // Write the FoodWastageTracker class here. Refer to your class design for the
  // member variables, constructors, and member functions needed.
  //
  // Note: mark functions that do not modify the member variables
  // as const, by writing `const` after the parameter list.
  // Pass objects by const reference when appropriate.
  // Remember that std::string is an object!
  // ===============================================================
 public:
  bool AddRecord(const FoodWastageRecord &record) {
    for (std::vector<FoodWastageRecord>::iterator it =
             food_wastage_records_.begin();
         it < food_wastage_records_.end(); it++) {
      if (it->Date() == record.Date() && it->Meal() == record.Meal() &&
          it->FoodName() == record.FoodName() &&
          it->QuantityInOz() == record.QuantityInOz() &&
          it->WastageReason() == record.WastageReason() &&
          it->DisposalMechanism() == record.DisposalMechanism() &&
          it->Cost() == record.Cost()) {
        return false;
      }
    } food_wastage_records_.push_back(record);
        return true;
  };
  bool DeleteRecord(const FoodWastageRecord &record);
  const std::vector<FoodWastageRecord> &GetRecords() const {
    return food_wastage_records_;
  };


 private:
  std::vector<FoodWastageRecord> food_wastage_records_;

};

#endif
