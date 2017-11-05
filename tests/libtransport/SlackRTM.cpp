#include "SlackRTM.h"
#include "SlackIdManager.h"
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "BasicSlackTest.h"

using namespace Transport;

class SlackRTMTest : public CPPUNIT_NS :: TestFixture, public BasicTest {
	CPPUNIT_TEST_SUITE(SlackRTMTest);
	CPPUNIT_TEST(handleRTMStart);
	CPPUNIT_TEST(handlePayloadReceivedChannelJoined);
	CPPUNIT_TEST(handlePayloadReceivedChannelCreated);
	CPPUNIT_TEST_SUITE_END();

	public:
		SlackRTM *m_rtm;
		SlackIdManager *m_idManager;
		std::string rtmStartPayload;

		void setUp (void) {
			setMeUp();
			UserInfo uinfo;
			uinfo.id = 1;
			m_idManager = new SlackIdManager();
			m_rtm = new SlackRTM(component, storage, m_idManager, uinfo);

			rtmStartPayload = "{\"ok\":true,\"self\":{\"id\":\"U0KECRDJB\",\"name\":\"spectrum2\",\"prefs\":{\"highlight_words\":\"\",\"user_colors\":\"\",\"color_names_in_list\":true,\"growls_enabled\":true,\"tz\":null,\"push_dm_alert\":true,\"push_mention_alert\":true,\"msg_replies\":\"{ \\\"flexpane\\\":false }\",\"push_everything\":true,\"push_idle_wait\":2,\"push_sound\":\"b2.mp3\",\"push_loud_channels\":\"\",\"push_mention_channels\":\"\",\"push_loud_channels_set\":\"\",\"email_alerts\":\"instant\",\"email_alerts_sleep_until\":0,\"email_misc\":true,\"email_weekly\":true,\"welcome_message_hidden\":false,\"all_channels_loud\":true,\"loud_channels\":\"\",\"never_channels\":\"\",\"loud_channels_set\":\"\",\"show_member_presence\":true,\"search_sort\":\"timestamp\",\"expand_inline_imgs\":true,\"expand_internal_inline_imgs\":true,\"expand_snippets\":false,\"posts_formatting_guide\":true,\"seen_live_support_popup\":false,\"seen_welcome_2\":false,\"seen_ssb_prompt\":false,\"seen_spaces_new_xp_tooltip\":false,\"spaces_new_xp_banner_dismissed\":false,\"search_only_my_channels\":false,\"emoji_mode\":\"default\",\"emoji_use\":\"\",\"has_invited\":false,\"has_uploaded\":false,\"has_created_channel\":false,\"search_exclude_channels\":\"\",\"messages_theme\":\"default\",\"webapp_spellcheck\":true,\"no_joined_overlays\":false,\"no_created_overlays\":false,\"dropbox_enabled\":false,\"seen_domain_invite_reminder\":false,\"seen_member_invite_reminder\":false,\"mute_sounds\":false,\"arrow_history\":false,\"tab_ui_return_selects\":true,\"obey_inline_img_limit\":true,\"new_msg_snd\":\"knock_brush.mp3\",\"collapsible\":false,\"collapsible_by_click\":true,\"require_at\":false,\"ssb_space_window\":\"\",\"mac_ssb_bounce\":\"\",\"mac_ssb_bullet\":true,\"expand_non_media_attachments\":true,\"show_typing\":true,\"pagekeys_handled\":true,\"last_snippet_type\":\"\",\"display_real_names_override\":0,\"time24\":false,\"enter_is_special_in_tbt\":false,\"graphic_emoticons\":false,\"convert_emoticons\":true,\"autoplay_chat_sounds\":true,\"ss_emojis\":true,\"sidebar_behavior\":\"\",\"seen_onboarding_start\":false,\"onboarding_cancelled\":false,\"seen_onboarding_slackbot_conversation\":false,\"seen_onboarding_channels\":false,\"seen_onboarding_direct_messages\":false,\"seen_onboarding_invites\":false,\"seen_onboarding_search\":false,\"seen_onboarding_recent_mentions\":false,\"seen_onboarding_starred_items\":false,\"seen_onboarding_private_groups\":false,\"onboarding_slackbot_conversation_step\":0,\"dnd_enabled\":false,\"dnd_start_hour\":\"22:00\",\"dnd_end_hour\":\"08:00\",\"mark_msgs_read_immediately\":true,\"start_scroll_at_oldest\":true,\"snippet_editor_wrap_long_lines\":false,\"ls_disabled\":false,\"sidebar_theme\":\"default\",\"sidebar_theme_custom_values\":\"\",\"f_key_search\":false,\"k_key_omnibox\":true,\"speak_growls\":false,\"mac_speak_voice\":\"com.apple.speech.synthesis.voice.Alex\",\"mac_speak_speed\":250,\"comma_key_prefs\":false,\"at_channel_suppressed_channels\":\"\",\"push_at_channel_suppressed_channels\":\"\",\"prompted_for_email_disabling\":false,\"full_text_extracts\":false,\"no_text_in_notifications\":false,\"muted_channels\":\"\",\"no_macssb1_banner\":false,\"no_winssb1_banner\":false,\"no_omnibox_in_channels\":false,\"k_key_omnibox_auto_hide_count\":0,\"hide_user_group_info_pane\":false,\"mentions_exclude_at_user_groups\":false,\"privacy_policy_seen\":true,\"search_exclude_bots\":false,\"fuzzy_matching\":false,\"load_lato_2\":false,\"fuller_timestamps\":false,\"last_seen_at_channel_warning\":0,\"flex_resize_window\":false,\"msg_preview\":false,\"msg_preview_displaces\":true,\"msg_preview_persistent\":true,\"emoji_autocomplete_big\":false,\"winssb_run_from_tray\":true,\"winssb_window_flash_behavior\":\"idle\",\"two_factor_auth_enabled\":false,\"two_factor_type\":null,\"two_factor_backup_type\":null,\"mentions_exclude_at_channels\":true,\"confirm_clear_all_unreads\":true,\"confirm_user_marked_away\":true,\"box_enabled\":false,\"seen_single_emoji_msg\":false,\"confirm_sh_call_start\":true,\"preferred_skin_tone\":\"\",\"show_all_skin_tones\":false,\"separate_private_channels\":false,\"whats_new_read\":1453832311,\"hotness\":false,\"frecency_jumper\":\"\",\"jumbomoji\":false},\"created\":1453832311,\"manual_presence\":\"active\"},\"team\":{\"id\":\"T0H6F57L0\",\"name\":\"spectrum2test\",\"email_domain\":\"\",\"domain\":\"spectrum2tests\",\"msg_edit_window_mins\":-1,\"prefs\":{\"default_channels\":[\"C0H6BKHM1\",\"C0H6EJD2S\"],\"gateway_allow_xmpp_ssl\":1,\"gateway_allow_irc_ssl\":0,\"gateway_allow_irc_plain\":0,\"msg_edit_window_mins\":-1,\"allow_message_deletion\":true,\"hide_referers\":true,\"display_real_names\":false,\"disable_file_uploads\":\"allow_all\",\"who_can_at_everyone\":\"regular\",\"who_can_at_channel\":\"ra\",\"warn_before_at_channel\":\"always\",\"who_can_create_channels\":\"regular\",\"who_can_create_shared_channels\":\"admin\",\"who_can_archive_channels\":\"regular\",\"who_can_create_groups\":\"ra\",\"who_can_post_general\":\"ra\",\"who_can_kick_channels\":\"admin\",\"who_can_kick_groups\":\"regular\",\"dnd_enabled\":true,\"dnd_start_hour\":\"22:00\",\"dnd_end_hour\":\"08:00\",\"allow_shared_channels\":false,\"who_has_team_visibility\":\"ra\",\"who_can_create_delete_user_groups\":\"admin\",\"who_can_edit_user_groups\":\"admin\",\"who_can_change_team_profile\":\"admin\",\"retention_type\":0,\"retention_duration\":0,\"group_retention_type\":0,\"group_retention_duration\":0,\"dm_retention_type\":0,\"dm_retention_duration\":0,\"file_retention_type\":0,\"file_retention_duration\":0,\"allow_retention_override\":true,\"require_at_for_mention\":0,\"compliance_export_start\":0,\"invites_only_admins\":true,\"auth_mode\":\"normal\",\"who_can_manage_integrations\":{\"type\":[\"regular\"]}},\"icon\":{\"image_34\":\"https:\\/\\/slack.global.ssl.fastly.net\\/0180\\/img\\/avatars-teams\\/ava_0020-34.png\",\"image_44\":\"https:\\/\\/slack.global.ssl.fastly.net\\/66f9\\/img\\/avatars-teams\\/ava_0020-44.png\",\"image_68\":\"https:\\/\\/slack.global.ssl.fastly.net\\/66f9\\/img\\/avatars-teams\\/ava_0020-68.png\",\"image_88\":\"https:\\/\\/slack.global.ssl.fastly.net\\/66f9\\/img\\/avatars-teams\\/ava_0020-88.png\",\"image_102\":\"https:\\/\\/slack.global.ssl.fastly.net\\/66f9\\/img\\/avatars-teams\\/ava_0020-102.png\",\"image_132\":\"https:\\/\\/slack.global.ssl.fastly.net\\/66f9\\/img\\/avatars-teams\\/ava_0020-132.png\",\"image_default\":true},\"over_storage_limit\":false,\"plan\":\"\",\"over_integrations_limit\":true},\"latest_event_ts\":\"1454230362.000000\",\"channels\":[{\"id\":\"C0H6BKHM1\",\"name\":\"general\",\"is_channel\":true,\"created\":1450796647,\"creator\":\"U0H6EEWNN\",\"is_archived\":false,\"is_general\":true,\"has_pins\":false,\"is_member\":false},{\"id\":\"C0HEF8JCU\",\"name\":\"irc_channel\",\"is_channel\":true,\"created\":1451370608,\"creator\":\"U0H6EEWNN\",\"is_archived\":false,\"is_general\":false,\"has_pins\":false,\"is_member\":false},{\"id\":\"C0KH09UQ2\",\"name\":\"my_new_channel\",\"is_channel\":true,\"created\":1453906652,\"creator\":\"U0H6EEWNN\",\"is_archived\":false,\"is_general\":false,\"has_pins\":false,\"is_member\":true,\"last_read\":\"1453906652.000002\",\"latest\":{\"user\":\"U0H6EEWNN\",\"purpose\":\"Online users: Jan Kaluza, \",\"type\":\"message\",\"subtype\":\"channel_purpose\",\"text\":\"<@U0H6EEWNN|owner> set the channel purpose: Online users: Jan Kaluza, \",\"ts\":\"1454230914.000002\"},\"unread_count\":8,\"unread_count_display\":7,\"members\":[\"U0H6EEWNN\",\"U0KECRDJB\"],\"topic\":{\"value\":\"\",\"creator\":\"\",\"last_set\":0},\"purpose\":{\"value\":\"Online users: Jan Kaluza, \",\"creator\":\"U0H6EEWNN\",\"last_set\":1454230914}},{\"id\":\"C0H6EJD2S\",\"name\":\"random\",\"is_channel\":true,\"created\":1450796647,\"creator\":\"U0H6EEWNN\",\"is_archived\":false,\"is_general\":false,\"has_pins\":false,\"is_member\":false},{\"id\":\"C0H6B0SQM\",\"name\":\"spectrum2_contactlist\",\"is_channel\":true,\"created\":1450797097,\"creator\":\"U0H6EEWNN\",\"is_archived\":false,\"is_general\":false,\"has_pins\":false,\"is_member\":false},{\"id\":\"C0H6FMUSU\",\"name\":\"spectrum2_room\",\"is_channel\":true,\"created\":1450797111,\"creator\":\"U0H6EEWNN\",\"is_archived\":false,\"is_general\":false,\"has_pins\":false,\"is_member\":false},{\"id\":\"C0KK70E92\",\"name\":\"spectrum_channel\",\"is_channel\":true,\"created\":1453969281,\"creator\":\"U0H6EEWNN\",\"is_archived\":false,\"is_general\":false,\"has_pins\":false,\"is_member\":false}],\"groups\":[],\"ims\":[{\"id\":\"D0KEDLA8Y\",\"is_im\":true,\"user\":\"USLACKBOT\",\"created\":1453832311,\"has_pins\":false,\"last_read\":\"0000000000.000000\",\"latest\":null,\"unread_count\":0,\"unread_count_display\":0,\"is_open\":true},{\"id\":\"D0KEC5UTT\",\"is_im\":true,\"user\":\"U0H6EEWNN\",\"created\":1453832311,\"has_pins\":false,\"last_read\":\"0000000000.000000\",\"latest\":{\"type\":\"message\",\"user\":\"U0KECRDJB\",\"text\":\"Unknown command. Use \\\".spectrum2 help\\\" for help.\",\"ts\":\"1454230892.000002\"},\"unread_count\":91,\"unread_count_display\":0,\"is_open\":true}],\"cache_ts\":1454230962,\"subteams\":{\"self\":[],\"all\":[]},\"dnd\":{\"dnd_enabled\":false,\"next_dnd_start_ts\":1,\"next_dnd_end_ts\":1,\"snooze_enabled\":false},\"users\":[{\"id\":\"U0HELRN5U\",\"team_id\":\"T0H6F57L0\",\"name\":\"anothertest\",\"deleted\":false,\"status\":null,\"color\":\"e7392d\",\"real_name\":\"\",\"tz\":null,\"tz_label\":\"Pacific Standard Time\",\"tz_offset\":-28800,\"profile\":{\"bot_id\":\"B0HEF7LJY\",\"api_app_id\":\"\",\"avatar_hash\":\"971145960e33\",\"image_24\":\"https:\\/\\/avatars.slack-edge.com\\/2015-12-29\\/17496560935_971145960e330b301ccd_24.png\",\"image_32\":\"https:\\/\\/avatars.slack-edge.com\\/2015-12-29\\/17496560935_971145960e330b301ccd_32.png\",\"image_48\":\"https:\\/\\/avatars.slack-edge.com\\/2015-12-29\\/17496560935_971145960e330b301ccd_48.png\",\"image_72\":\"https:\\/\\/avatars.slack-edge.com\\/2015-12-29\\/17496560935_971145960e330b301ccd_72.png\",\"image_192\":\"https:\\/\\/avatars.slack-edge.com\\/2015-12-29\\/17496560935_971145960e330b301ccd_192.png\",\"image_512\":\"https:\\/\\/avatars.slack-edge.com\\/2015-12-29\\/17496560935_971145960e330b301ccd_512.png\",\"image_1024\":\"https:\\/\\/avatars.slack-edge.com\\/2015-12-29\\/17496560935_971145960e330b301ccd_512.png\",\"image_original\":\"https:\\/\\/avatars.slack-edge.com\\/2015-12-29\\/17496560935_971145960e330b301ccd_original.png\",\"real_name\":\"\",\"real_name_normalized\":\"\",\"fields\":null},\"is_admin\":false,\"is_owner\":false,\"is_primary_owner\":false,\"is_restricted\":false,\"is_ultra_restricted\":false,\"is_bot\":true,\"presence\":\"away\"},{\"id\":\"U0H6EEWNN\",\"team_id\":\"T0H6F57L0\",\"name\":\"owner\",\"deleted\":false,\"status\":null,\"color\":\"9f69e7\",\"real_name\":\"\",\"tz\":\"Europe\\/Amsterdam\",\"tz_label\":\"Central European Time\",\"tz_offset\":3600,\"profile\":{\"avatar_hash\":\"g271b7615bd5\",\"real_name\":\"\",\"real_name_normalized\":\"\",\"email\":\"hanzz.k@gmail.com\",\"image_24\":\"https:\\/\\/secure.gravatar.com\\/avatar\\/271b7615bd58df47d63e5204e04ee65d.jpg?s=24&d=https%3A%2F%2Fslack.global.ssl.fastly.net%2F66f9%2Fimg%2Favatars%2Fava_0007-24.png\",\"image_32\":\"https:\\/\\/secure.gravatar.com\\/avatar\\/271b7615bd58df47d63e5204e04ee65d.jpg?s=32&d=https%3A%2F%2Fslack.global.ssl.fastly.net%2F66f9%2Fimg%2Favatars%2Fava_0007-32.png\",\"image_48\":\"https:\\/\\/secure.gravatar.com\\/avatar\\/271b7615bd58df47d63e5204e04ee65d.jpg?s=48&d=https%3A%2F%2Fslack.global.ssl.fastly.net%2F66f9%2Fimg%2Favatars%2Fava_0007-48.png\",\"image_72\":\"https:\\/\\/secure.gravatar.com\\/avatar\\/271b7615bd58df47d63e5204e04ee65d.jpg?s=72&d=https%3A%2F%2Fslack.global.ssl.fastly.net%2F66f9%2Fimg%2Favatars%2Fava_0007-72.png\",\"image_192\":\"https:\\/\\/secure.gravatar.com\\/avatar\\/271b7615bd58df47d63e5204e04ee65d.jpg?s=192&d=https%3A%2F%2Fslack.global.ssl.fastly.net%2F7fa9%2Fimg%2Favatars%2Fava_0007-192.png\",\"image_512\":\"https:\\/\\/secure.gravatar.com\\/avatar\\/271b7615bd58df47d63e5204e04ee65d.jpg?s=512&d=https%3A%2F%2Fslack.global.ssl.fastly.net%2F7fa9%2Fimg%2Favatars%2Fava_0007-512.png\",\"fields\":null},\"is_admin\":true,\"is_owner\":true,\"is_primary_owner\":true,\"is_restricted\":false,\"is_ultra_restricted\":false,\"is_bot\":false,\"presence\":\"away\"},{\"id\":\"U0H69GY5S\",\"team_id\":\"T0H6F57L0\",\"name\":\"spectrum2\",\"deleted\":false,\"status\":null,\"color\":\"4bbe2e\",\"real_name\":\"\",\"tz\":null,\"tz_label\":\"Pacific Standard Time\",\"tz_offset\":-28800,\"profile\":{\"bot_id\":\"B0H6AU1HT\",\"api_app_id\":\"\",\"avatar_hash\":\"f8d23ca2bfcf\",\"image_24\":\"https:\\/\\/avatars.slack-edge.com\\/2015-12-22\\/17213576228_f8d23ca2bfcf67d184ad_24.png\",\"image_32\":\"https:\\/\\/avatars.slack-edge.com\\/2015-12-22\\/17213576228_f8d23ca2bfcf67d184ad_32.png\",\"image_48\":\"https:\\/\\/avatars.slack-edge.com\\/2015-12-22\\/17213576228_f8d23ca2bfcf67d184ad_48.png\",\"image_72\":\"https:\\/\\/avatars.slack-edge.com\\/2015-12-22\\/17213576228_f8d23ca2bfcf67d184ad_72.png\",\"image_192\":\"https:\\/\\/avatars.slack-edge.com\\/2015-12-22\\/17213576228_f8d23ca2bfcf67d184ad_192.png\",\"image_512\":\"https:\\/\\/avatars.slack-edge.com\\/2015-12-22\\/17213576228_f8d23ca2bfcf67d184ad_512.png\",\"image_1024\":\"https:\\/\\/avatars.slack-edge.com\\/2015-12-22\\/17213576228_f8d23ca2bfcf67d184ad_512.png\",\"image_original\":\"https:\\/\\/avatars.slack-edge.com\\/2015-12-22\\/17213576228_f8d23ca2bfcf67d184ad_original.png\",\"real_name\":\"\",\"real_name_normalized\":\"\",\"fields\":null},\"is_admin\":false,\"is_owner\":false,\"is_primary_owner\":false,\"is_restricted\":false,\"is_ultra_restricted\":false,\"is_bot\":true,\"presence\":\"away\"},{\"id\":\"U0KECRDJB\",\"team_id\":\"T0H6F57L0\",\"name\":\"spectrum22\",\"deleted\":false,\"status\":null,\"color\":\"3c989f\",\"real_name\":\"Spectrum 2\",\"tz\":null,\"tz_label\":\"Pacific Standard Time\",\"tz_offset\":-28800,\"profile\":{\"first_name\":\"Spectrum 2\",\"bot_id\":\"B0KE9SE83\",\"api_app_id\":\"A0ET5FEUT\",\"avatar_hash\":\"g54f5aa0341b\",\"real_name\":\"Spectrum 2\",\"real_name_normalized\":\"Spectrum 2\",\"image_24\":\"https:\\/\\/secure.gravatar.com\\/avatar\\/54f5aa0341b1d9b9bce259906cf8354d.jpg?s=24&d=https%3A%2F%2Fslack.global.ssl.fastly.net%2F66f9%2Fimg%2Favatars%2Fava_0001-24.png\",\"image_32\":\"https:\\/\\/secure.gravatar.com\\/avatar\\/54f5aa0341b1d9b9bce259906cf8354d.jpg?s=32&d=https%3A%2F%2Fslack.global.ssl.fastly.net%2F66f9%2Fimg%2Favatars%2Fava_0001-32.png\",\"image_48\":\"https:\\/\\/secure.gravatar.com\\/avatar\\/54f5aa0341b1d9b9bce259906cf8354d.jpg?s=48&d=https%3A%2F%2Fslack.global.ssl.fastly.net%2F0180%2Fimg%2Favatars%2Fava_0001-48.png\",\"image_72\":\"https:\\/\\/secure.gravatar.com\\/avatar\\/54f5aa0341b1d9b9bce259906cf8354d.jpg?s=72&d=https%3A%2F%2Fslack.global.ssl.fastly.net%2F3654%2Fimg%2Favatars%2Fava_0001-72.png\",\"image_192\":\"https:\\/\\/secure.gravatar.com\\/avatar\\/54f5aa0341b1d9b9bce259906cf8354d.jpg?s=192&d=https%3A%2F%2Fslack.global.ssl.fastly.net%2F7fa9%2Fimg%2Favatars%2Fava_0001-192.png\",\"image_512\":\"https:\\/\\/secure.gravatar.com\\/avatar\\/54f5aa0341b1d9b9bce259906cf8354d.jpg?s=512&d=https%3A%2F%2Fslack.global.ssl.fastly.net%2F7fa9%2Fimg%2Favatars%2Fava_0001-512.png\",\"fields\":null},\"is_admin\":false,\"is_owner\":false,\"is_primary_owner\":false,\"is_restricted\":false,\"is_ultra_restricted\":false,\"is_bot\":true,\"presence\":\"away\"},{\"id\":\"USLACKBOT\",\"team_id\":\"T0H6F57L0\",\"name\":\"slackbot\",\"deleted\":false,\"status\":null,\"color\":\"757575\",\"real_name\":\"slackbot\",\"tz\":null,\"tz_label\":\"Pacific Standard Time\",\"tz_offset\":-28800,\"profile\":{\"first_name\":\"slackbot\",\"last_name\":\"\",\"image_24\":\"https:\\/\\/slack.global.ssl.fastly.net\\/0180\\/img\\/slackbot_24.png\",\"image_32\":\"https:\\/\\/slack.global.ssl.fastly.net\\/66f9\\/img\\/slackbot_32.png\",\"image_48\":\"https:\\/\\/slack.global.ssl.fastly.net\\/66f9\\/img\\/slackbot_48.png\",\"image_72\":\"https:\\/\\/slack.global.ssl.fastly.net\\/0180\\/img\\/slackbot_72.png\",\"image_192\":\"https:\\/\\/slack.global.ssl.fastly.net\\/66f9\\/img\\/slackbot_192.png\",\"image_512\":\"https:\\/\\/slack.global.ssl.fastly.net\\/7fa9\\/img\\/slackbot_512.png\",\"avatar_hash\":\"sv1444671949\",\"real_name\":\"slackbot\",\"real_name_normalized\":\"slackbot\",\"email\":null,\"fields\":null},\"is_admin\":false,\"is_owner\":false,\"is_primary_owner\":false,\"is_restricted\":false,\"is_ultra_restricted\":false,\"is_bot\":false,\"presence\":\"active\"}],\"cache_version\":\"v12-rats\",\"cache_ts_version\":\"v1-cat\",\"bots\":[{\"id\":\"B0H6AU1HT\",\"deleted\":false,\"name\":\"bot\",\"icons\":{\"image_36\":\"https:\\/\\/slack.global.ssl.fastly.net\\/12b5a\\/plugins\\/bot\\/assets\\/service_36.png\",\"image_48\":\"https:\\/\\/slack.global.ssl.fastly.net\\/12b5a\\/plugins\\/bot\\/assets\\/service_48.png\",\"image_72\":\"https:\\/\\/slack.global.ssl.fastly.net\\/12b5a\\/plugins\\/bot\\/assets\\/service_72.png\"}},{\"id\":\"B0H6F5BDE\",\"deleted\":false,\"name\":\"gdrive\"},{\"id\":\"B0HEF7LJY\",\"deleted\":false,\"name\":\"bot\",\"icons\":{\"image_36\":\"https:\\/\\/slack.global.ssl.fastly.net\\/12b5a\\/plugins\\/bot\\/assets\\/service_36.png\",\"image_48\":\"https:\\/\\/slack.global.ssl.fastly.net\\/12b5a\\/plugins\\/bot\\/assets\\/service_48.png\",\"image_72\":\"https:\\/\\/slack.global.ssl.fastly.net\\/12b5a\\/plugins\\/bot\\/assets\\/service_72.png\"}},{\"id\":\"B0KE9SE83\",\"deleted\":false,\"name\":\"Spectrum 2\",\"icons\":{\"image_36\":\"https:\\/\\/slack.global.ssl.fastly.net\\/12b5a\\/plugins\\/app\\/assets\\/service_36.png\",\"image_48\":\"https:\\/\\/slack.global.ssl.fastly.net\\/12b5a\\/plugins\\/app\\/assets\\/service_48.png\",\"image_72\":\"https:\\/\\/slack.global.ssl.fastly.net\\/12b5a\\/plugins\\/app\\/assets\\/service_72.png\"}}],\"url\":\"wss:\\/\\/ms607.slack-msgs.com\\/websocket\\/qErn8B_c2XF7Xv7weT-YVYUeaxo0BGY5dzeyh_TjHPYrBivZfpaEXGITASOUtuT6856_MQoyLZybo-1R5-jY2cILbSskPs3uGJClpJqA_jTwHz00Sflcvp-Zoc8l5lCxnWQMJiGXtC7kKeLl4rme5g==\"}";
		}

		void tearDown (void) {
			delete m_rtm;
			delete m_idManager;
			tearMeDown();
		}

		void handleRTMStart() {
			rapidjson::Document json;
			json.Parse<0>(rtmStartPayload.c_str());
			m_rtm->handleRTMStart(NULL, true, json, rtmStartPayload);

			CPPUNIT_ASSERT_EQUAL(std::string("spectrum2"), m_idManager->getSelfName());
			CPPUNIT_ASSERT_EQUAL(std::string("U0KECRDJB"), m_idManager->getSelfId());
			CPPUNIT_ASSERT_EQUAL(std::string("owner"), m_idManager->getName("U0H6EEWNN"));
			CPPUNIT_ASSERT_EQUAL(std::string("C0H6B0SQM"), m_idManager->getId("spectrum2_contactlist"));
			CPPUNIT_ASSERT_EQUAL(true, m_idManager->hasMember("C0KH09UQ2", "U0KECRDJB"));
			CPPUNIT_ASSERT_EQUAL(false, m_idManager->hasMember("C0KH09UQ2", "U1KECRDJB"));
		}

		void handlePayloadReceivedChannelJoined() {
			CPPUNIT_ASSERT_EQUAL(false, m_idManager->hasMember("C0KSK7V7E", "U0KECRDJB"));

			std::string payload = "{\"type\":\"channel_joined\",\"channel\":{\"id\":\"C0KSK7V7E\",\"name\":\"new_slack_channel\",\"is_channel\":true,\"created\":1454231085,\"creator\":\"U0H6EEWNN\",\"is_archived\":false,\"is_general\":false,\"is_member\":true,\"last_read\":\"1454231085.000002\",\"latest\":{\"user\":\"U0H6EEWNN\",\"type\":\"message\",\"subtype\":\"channel_join\",\"text\":\"<@U0H6EEWNN|owner> has joined the channel\",\"ts\":\"1454231085.000002\"},\"unread_count\":0,\"unread_count_display\":0,\"members\":[\"U0H6EEWNN\",\"U0KECRDJB\"],\"topic\":{\"value\":\"\",\"creator\":\"\",\"last_set\":0},\"purpose\":{\"value\":\"\",\"creator\":\"\",\"last_set\":0}}}";
			m_rtm->handlePayloadReceived(payload);
			CPPUNIT_ASSERT_EQUAL(std::string("C0KSK7V7E"), m_idManager->getId("new_slack_channel"));
			CPPUNIT_ASSERT_EQUAL(true, m_idManager->hasMember("C0KSK7V7E", "U0KECRDJB"));
			CPPUNIT_ASSERT_EQUAL(false, m_idManager->hasMember("C0KSK7V7E", "U1KECRDJB"));
		}


		void handlePayloadReceivedChannelCreated() {
			std::string payload = "{\"type\":\"channel_created\",\"channel\":{\"id\":\"C0KH09UQ2\",\"is_channel\":true,\"name\":\"my_new_channel\",\"created\":1453906652,\"creator\":\"U0H6EEWNN\"},\"event_ts\":\"1453906652.085393\"}";
			m_rtm->handlePayloadReceived(payload);
			CPPUNIT_ASSERT_EQUAL(std::string("C0KH09UQ2"), m_idManager->getId("my_new_channel"));
		}

};

CPPUNIT_TEST_SUITE_REGISTRATION (SlackRTMTest);