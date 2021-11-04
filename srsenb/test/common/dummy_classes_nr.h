/**
 *
 * \section COPYRIGHT
 *
 * Copyright 2013-2021 Software Radio Systems Limited
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the distribution.
 *
 */

#ifndef SRSRAN_DUMMY_NR_CLASSES_H
#define SRSRAN_DUMMY_NR_CLASSES_H

#include "srsran/interfaces/gnb_interfaces.h"
#include "srsran/interfaces/gnb_mac_interfaces.h"

namespace srsenb {

class rrc_nr_dummy : public rrc_interface_mac_nr
{
public:
  int  read_pdu_bcch_bch(const uint32_t tti, srsran::byte_buffer_t& buffer) { return SRSRAN_SUCCESS; }
  int  read_pdu_bcch_dlsch(uint32_t sib_index, srsran::byte_buffer_t& buffer) { return SRSRAN_SUCCESS; }
  int  add_user(uint16_t rnti, const sched_nr_ue_cfg_t& uecfg) { return SRSRAN_SUCCESS; }
  int  update_user(uint16_t new_rnti, uint16_t old_rnti) { return SRSRAN_SUCCESS; }
  void set_activity_user(uint16_t rnti) {}
};

class rlc_nr_dummy : public rlc_interface_mac_nr
{
public:
  int  read_pdu(uint16_t rnti, uint32_t lcid, uint8_t* payload, uint32_t nof_bytes) override { return SRSRAN_SUCCESS; }
  void read_pdu_pcch(uint8_t* payload, uint32_t buffer_size) override {}
  void write_pdu(uint16_t rnti, uint32_t lcid, uint8_t* payload, uint32_t nof_bytes) override {}
};

class mac_nr_dummy : public mac_interface_rrc_nr
{
public:
  int cell_cfg(const std::vector<srsenb::sched_nr_interface::cell_cfg_t>& nr_cells) override { return SRSRAN_SUCCESS; }
  uint16_t reserve_rnti(uint32_t enb_cc_idx, const sched_nr_ue_cfg_t& uecfg) override { return 0x4601; }

  int ue_cfg(uint16_t rnti, const sched_nr_interface::ue_cfg_t& ue_cfg) override { return SRSRAN_SUCCESS; }

  int remove_ue(uint16_t rnti) override { return SRSRAN_SUCCESS; }

  srsenb::sched_interface::cell_cfg_t cellcfgobj;
};

class phy_nr_dummy : public phy_interface_stack_nr
{
public:
  int set_common_cfg(const phy_interface_rrc_nr::common_cfg_t& common_cfg_) override { return SRSRAN_SUCCESS; }
};

} // namespace srsenb

#endif // SRSRAN_DUMMY_NR_CLASSES_H
