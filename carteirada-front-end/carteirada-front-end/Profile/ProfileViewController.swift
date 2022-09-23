//
//  ProfileViewController.swift
//  carteirada-front-end
//
//  Created by Robson Novato Lobao on 19/09/22.
//

import Foundation
import UIKit

class ProfileViewController: UIViewController {
    @IBOutlet weak var emailField: UIView!
    @IBOutlet weak var userField: UIView!
    
    @IBOutlet weak var email: UILabel!
    @IBOutlet weak var user: UILabel!
    
    @IBOutlet weak var exitButtonEdit: UIButton!
    
    override func viewDidLoad() {
        setupFirstField()
        setupSecondField()
        setupEmailAndUser()
        setupButton()
    }
    
    func setupButton() {
        exitButtonEdit.layer.cornerRadius = 20
        exitButtonEdit.layer.shadowColor = UIColor.black.cgColor
        exitButtonEdit.layer.shadowOffset = CGSize(width: 0.0, height: 4.0)
        exitButtonEdit.layer.shadowRadius = 4.0
        exitButtonEdit.layer.shadowOpacity = 0.5
        exitButtonEdit.layer.masksToBounds = false
    }
    
    func setupEmailAndUser() {
        email.text = UserDefaults.standard.string(forKey: "email")
        user.text = UserDefaults.standard.string(forKey: "usuario")
    }
    
    func setupFirstField() {
        emailField.layer.cornerRadius = 20
        emailField.layer.borderWidth = 0.5
        emailField.layer.borderColor = UIColor(red: 0.669, green: 0.669, blue: 0.669, alpha: 1).cgColor
    }
    
    func setupSecondField() {
        userField.layer.cornerRadius = 20
        userField.layer.borderWidth = 0.5
        userField.layer.borderColor = UIColor(red: 0.669, green: 0.669, blue: 0.669, alpha: 1).cgColor
    }
    
    @IBAction func exitButton(_ sender: Any) {
        UserDefaults.standard.set(false, forKey: "logado3")
        let myViewController = Register2ViewController()
        myViewController.modalPresentationStyle = .fullScreen
        self.present(myViewController, animated: true, completion: nil)
    }
}
